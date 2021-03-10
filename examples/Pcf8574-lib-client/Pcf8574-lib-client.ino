
#include "Pcf8574.h"
#include "Pcf8574Board.h"

#define NO_OF_BOARDS 8

int MAX_PINS = 0;

Pcf8574Board pcf8574Board;

void setup() {
  Serial.begin(9600);
  
  pcf8574Board.initPcf8574Boards(NO_OF_BOARDS);  
  MAX_PINS = NO_OF_BOARDS * 8;
}

void loop() {
  int pinNo = random(0, MAX_PINS);
  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  Serial.print("PIN NO ");
  Serial.println(pinNo);
  delay(1000);
  pcf8574Board.switchOn(pinNo);
  pcf8574Board.displayPinState();
  delay(1000);
  pcf8574Board.switchOff(pinNo);
  pcf8574Board.displayPinState();
  delay(1000);
}
