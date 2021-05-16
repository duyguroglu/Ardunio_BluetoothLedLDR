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
<img src="https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/pins.jpg?raw=true" alt="drawing" width="200"/>            |  <img src="https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/circuit_schematic.jpg?raw=true" alt="drawing" width="600"/> 

LED is put in series with the 330 ohm resistor and connected to the ground. Input and voltage comes from the GPIO 3 pin.

LDR is put in series with the 10k ohm resistor and connected to the ground. Input voltage comes from the 3.3V pin and the GPIO 5 pin is connected between the LDR and resistor.

Final circuit is connected to the RFDunio.
***
## Codes for Ardunio

Codes for the ardunio side can be accessed through [here](https://github.com/duyguroglu/BluetoothLedLDR/tree/main/ardunio).
***
## Codes for the application

Codes for the Andriod application side can be accessed through [here](https://github.com/duyguroglu/BluetoothLedLDR/tree/main/app).

***
## Final prototype
[<img src="https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/video_screenshot.jpeg?raw=true">](https://player.vimeo.com/video/149284496)
<img src="https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/final_overview.jpg?raw=true" alt="drawing" width="600"/>            |  <img src="https://github.com/duyguroglu/BluetoothLedLDR/blob/main/project_images/final_overview2.jpg?raw=true" alt="drawing" width="300"/> 

The video shows the final working prototype.

Of course, since we are not programmers, there is a lot to improve. This instructable only shows the very first basics on how to manipulate the existing software to use the bluetooth input as bluetooth output.
### Some suggestions for improvement

- Instead of creating a new text box for every input (the list becomes very long as you can see in the video), the input could be displayed in just one text box where the number would change instead of adding a new number to it.

- The old buttons from the applications could be removed.

- New feedback on the on/off state of the LED could be given.

### Potential application

We used BLE to activate or deactivate a light when it is connected to our Android application. However, this is just a basic application but has great potential to become something of interest. For example, this method could be be used to create a remote controller to change the home lighting environment. With a low light intensity of the environment, the light will be activated by itself as soon as it connects to the application via Bluetooth. Entering and leaving a room could then automatically turn on or off the lights, saving energy.
