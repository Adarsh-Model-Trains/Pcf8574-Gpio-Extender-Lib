#include "Pcf8574.h"
#include "Pcf8574Board.h"

Pcf8574Board pcf8574Board;

#define NO_OF_BOARDS 3
int MAX_PINS = 0;

void setup() {
  Serial.begin(9600);
  pcf8574Board.setTotalPcf8574Boards(NO_OF_BOARDS);
  pcf8574Board.initPcf8574Boards();
  MAX_PINS = NO_OF_BOARDS * 8;
}

void loop() {

  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  pcf8574Board.switchOn(1);
  pcf8574Board.switchOn(8);
  pcf8574Board.switchOn(9);
  pcf8574Board.switchOn(16);
  pcf8574Board.switchOn(17);
  pcf8574Board.switchOn(24);
  pcf8574Board.displayPinState();
  delay(1000);
  pcf8574Board.switchOff(1);
  pcf8574Board.switchOff(8);
  pcf8574Board.switchOff(9);
  pcf8574Board.switchOff(16);
  pcf8574Board.switchOff(17);
  pcf8574Board.switchOff(24);
  pcf8574Board.displayPinState();
  delay(1000);

}
