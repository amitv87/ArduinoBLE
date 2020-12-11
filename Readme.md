# An Arduino Emulator (for Jupyter)

I really wanted to have an interactive [Jupyter](https://jupyter.org/) environemnt in which I could play around interactivly with [Arduino](https://www.arduino.cc/) commands and when I discovered that Arduino provides a good starting point with their [ArduinoCore-API](https://github.com/arduino/ArduinoCore-API/tree/105276f8d81413391b14a3dc6c80180ee9e33d56) I started to draft this prototype.

I am using [xeus-cling](https://github.com/jupyter-xeus/xeus-cling) as a runtime environment to simulate an Arduino Development board and I have added the related implementation using C or the C++ std library.

The goal is finally to be able to provide different alternative implementations
- Using wiringPI to be run on a Raspberry PI
- Output to a file from where it can be analysed
- Using a Stream interface to comuincate with an real Arduino Device.
- Using some standard Linux userspace APIs for GPIO

I have a __first working prototype__ ready but naturally there is still a lot to do:

## Content
- [Setup](01-Setup.ipynb)
- [Introduction into some Basic Commands](02-BasicCommands.ipynb)
- [The Network Stack](03-Network.ipynb)