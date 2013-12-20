#include "Boards.h"
#include <ble_mini.h>

const int pin = 4; // lets stay with pin 4.
const int pinMissed = 8;
byte buf[] = {'N','I','N','J','A'};
int incoming;
const int R = 9;
const int G = 10;
const int B = 11;

void setup() {
  BLEMini_begin(57600); // start the BLE device
  // Serial.begin(57600);
  pinMode(pin, OUTPUT);
  pinMode(pinMissed, OUTPUT);
}

void loop() {
  while(BLEMini_available()) {
    byte cmd = BLEMini_read(); // read command.
    byte toggleState = BLEMini_read();// read 0 or 1.
    byte extraData = BLEMini_read();
    switch(cmd) {
      case 0x01:
        switch(toggleState) {
          case 0x00:
            digitalWrite(pin, LOW);
            break;
          case 0x01:
            digitalWrite(pin, HIGH);
            if(extraData == 0x01)
              BLEMini_write_bytes(buf, 5);
            break;
        }
        break;
      case 0xA2:
        switch(toggleState) {
          case 0xA1:
            digitalWrite(pinMissed, HIGH);
            break;
          case 0xA0:
            digitalWrite(pinMissed, LOW);
            break;
        }
        break;
      case 0x02:
        switch(extraData) {
          case 0x00:
            analogWrite(R, toggleState);
            break;
          case 0x01:
            analogWrite(G, toggleState);
            break;
          case 0x02:
            analogWrite(B, toggleState);
            break;
        }
       break;
    }
  }
}
