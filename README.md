# Bluetooth Controlled LED With Analogue LDR Input
***

We wrote a test program for the RFduino and the test application for Android. Our aim was to send an analogue input signal via bluetooth to the controller that controls the actuator also via bluetooth (see the block diagram below). The old sample used a digital button input and the application provided a separate function to turn on or off the LED.

With the help of the RFduino module, we managed to get an analogue LDR input and send it via Bluetooth to a smartphone application. In the same application, this input was rerouted as output and send via bluetooth to control an LED connected with the RFduino (see block diagram).

***
## Required Elements
![components](https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/components.jpg?raw=true)
### Required Hardware
- RFD22102 RFduino DIP
- RFD22121 USB Shield
- LED
- LDR
- 10K ohm resistor
- 330 ohm resistor
- Wire set
- Breadboard
### Required Software
- [Ardunio C library](https://www.arduino.cc/en/Main/Software)
- [RDDunio Drivers (in case not automatically installed)](http://www.ftdichip.com/Drivers/VCP.htm)
- [RFDunio C library](https://github.com/lann/RFDuinoTest)
- [Android IDE (We used Android Studio)](http://developer.android.com/sdk/index.html)
- [RFDunio TestApp by @Iann](https://github.com/lann/RFDuinoTest)
***
## Preparation

![ardunio](https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/ardunio.jpg?raw=true)             |  ![ardunio2](https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/ardunio2.jpg?raw=true) 
:-------------------------:|:-------------------------:
  |  ![plugged](https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/plugged.jpg?raw=true) 
  
Following the download and install of required libraries & IDEs, we connect RFDunio to our computer.
***
## Circuit Schematic
![pins](https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/pins.jpg?raw=true)             |  ![circuit_schematic](https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/circuit_schematic.jpg?raw=true) 
