# Smart_Bin_001

Smart Bin Control using Arduino

Overview

This project is an automatic bin control system using an ultrasonic sensor, servo motor, LEDs, and a buzzer. The bin lid opens when an object is detected within a specified distance and closes when the object is removed.

**Components Required
**
Arduino Board

Ultrasonic Sensor (HC-SR04)

Servo Motor (SG90 or MG995)

LED (2x)

Buzzer

Jumper Wires

Resistors (as needed)

Circuit Connections

**Component**

**Arduino                     Pin
**
Trig (HC-SR04)                 5

Echo (HC-SR04)                 6

Servo Signal                   7

Buzzer                         8

Status LED                     9

Blinking LED                   10

Code



**How It Works**

Distance Measurement: The ultrasonic sensor detects objects within 15 cm.

Bin Lid Control: The servo opens (0°) when an object is detected and closes (150°) otherwise.

Status Indication:

Status LED turns ON when the bin lid is open.

Buzzer beeps when the bin lid is open.

Blinking LED indicates no object is detected.

Future Enhancements

Add an LCD display for distance readings.

Integrate with IoT for remote monitoring.

Optimize power consumption for battery operation.



