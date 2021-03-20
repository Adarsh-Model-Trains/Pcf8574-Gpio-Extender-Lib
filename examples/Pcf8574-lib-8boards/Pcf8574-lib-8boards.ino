#include "Pcf8574.h"
#include "Pcf8574Board.h"

Pcf8574Board pcf8574Board;

#define NO_OF_BOARDS 8
int MAX_PINS = 0;

void setup() {
  Serial.begin(9600);
  pcf8574Board.initPcf8574Boards(NO_OF_BOARDS);
  MAX_PINS = NO_OF_BOARDS * 8;
}

void loop() {

  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);

  for (int i = 1; i <= MAX_PINS; i++) {
    pcf8574Board.switchOn(i);
  }
  delay(1000);

  for (int i = 1; i <= MAX_PINS; i++) {
    pcf8574Board.switchOff(i);
  }
  delay(1000);
}
