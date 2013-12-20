Moody1
======

Bluetooth Low energy based mood lighting. It also acts as a beacon detecting user's presence and gives missed call/incoming call notifications.
The bluetooth module is BLE Mini from Red Bear Labs. The Arduino code defines which LED goes where. I used a RGB led on pin 4
to act as a beacon that lights up when it detects the user's presence and sends a welcome message to the user.
A red LED on pin 8 is used to notify for incoming and missed calls.

Pin 9, 10 and 11 are PWM pins that we can control using the app and set up the ambiance according to our mood.
