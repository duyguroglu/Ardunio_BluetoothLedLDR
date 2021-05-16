# Bluetooth Controlled LED With Analogue LDR Input
***

We wrote a test program for the RFduino and the test application for Android. Our aim was to send an analogue input signal via bluetooth to the controller that controls the actuator also via bluetooth (see the block diagram below). The old sample used a digital button input and the application provided a separate function to turn on or off the LED.

With the help of the RFduino module, we managed to get an analogue LDR input and send it via Bluetooth to a smartphone application. In the same application, this input was rerouted as output and send via bluetooth to control an LED connected with the RFduino (see block diagram).

***
## Required Elements
