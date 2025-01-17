#pragma once

#if PROVIDE_SERIALLIB

#include "serialib.h"
#include "HardwareSerial.h"

namespace arduino {

/**
 * Arduino Stream implementation which is using serialib
 * https://github.com/imabot2/serialib
 */

class SerialImpl : public HardwareSerial {
    public:
        SerialImpl(const char* device = "/dev/ttyACM0"){
            this->device = device;
        }
    
        virtual void begin(unsigned long baudrate) {
            open(baudrate);
        }
    
        virtual void begin(unsigned long baudrate, uint16_t config) {    
            open(baudrate);
        }
    
        virtual void end() {
            is_open = false;
            serial.closeDevice();
        }
    
        virtual int available(void) {
            return serial.available();
        };
    
        virtual int peek(void) {
            if (peek_char==-1){
                peek_char = read();
            }
            return peek_char;
        }

        virtual int read(void) {
            int result = -1;
            if (peek_char!=-1){
                result = peek_char;
                peek_char = -1;
            } else {
                char c;
                result = serial.readChar(&c, timeout);
                result = result == 1 ? c : -1;
            }
            return result;
        };
    
        virtual void flush(void) {
        };
    
        virtual size_t write(uint8_t c) {
            return serial.writeChar(c);
        }
    
        virtual operator bool(){
            return is_open;
        }
        
        // sets maximum milliseconds to wait for stream data, default is 1 second
        void setTimeout(unsigned long timeout){
            this->timeout = timeout;
            HardwareSerial::setTimeout(timeout);
        }

    protected:
        const char* device;
        serialib serial;
        bool is_open = false;
        int peek_char = -1;
        long timeout = 1000;

        virtual void open(unsigned long baudrate) {
            if(is_open) return;
            int rc = serial.openDevice(device, baudrate);
            printf("openDevice %s -> %d\r\n", device, rc);

            if (serial.openDevice(device, baudrate) != 1){
            }
            is_open=true;
        }

};
    
extern SerialImpl Serial1; 
    
} // namespace

#endif