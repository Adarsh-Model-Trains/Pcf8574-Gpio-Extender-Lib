#include "Pcf8574.h"
#include "Pcf8574Board.h"

Pcf8574Board pcf8574Board;

#define NO_OF_BOARDS 4
int MAX_PINS = 0;

void setup() {
  Serial.begin(9600);
  pcf8574Board.initPcf8574Boards(NO_OF_BOARDS);
  MAX_PINS = NO_OF_BOARDS * 8;
}

void loop() {

  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  
  pcf8574Board.switchOn(1); // 1st board 1st and last pin
  pcf8574Board.switchOn(8);
  
  pcf8574Board.switchOn(9); // 2nd board 1st and last pin
  pcf8574Board.switchOn(16);
  
  pcf8574Board.switchOn(17); // 3rd board 1st and last pin
  pcf8574Board.switchOn(24);
  
  pcf8574Board.switchOn(25); // 4th board 1st and last pin
  pcf8574Board.switchOn(32);
  
  pcf8574Board.switchOn(33); // 5th board 1st and last pin
  pcf8574Board.switchOn(40);
  
  pcf8574Board.switchOn(41); // 6th board 1st and last pin
  pcf8574Board.switchOn(48);
  
  pcf8574Board.switchOn(49);  // 7th board 1st and last pin
  pcf8574Board.switchOn(54);
  
  pcf8574Board.switchOn(55);  // 8th board 1st and last pin
  pcf8574Board.switchOn(64);
  
  pcf8574Board.displayPinState();
  delay(1000);
  pcf8574Board.switchOff(1);
  pcf8574Board.switchOff(8);
  
  pcf8574Board.switchOff(9);
  pcf8574Board.switchOff(16);
  
  pcf8574Board.switchOff(17);
  pcf8574Board.switchOff(24);
  
  pcf8574Board.switchOff(25);
  pcf8574Board.switchOff(32);
  
  pcf8574Board.switchOff(33);
  pcf8574Board.switchOff(40);
  
  pcf8574Board.switchOff(41);
  pcf8574Board.switchOff(48);
  
  pcf8574Board.switchOff(49);
  pcf8574Board.switchOff(54);
  
  pcf8574Board.switchOff(55);
  pcf8574Board.switchOff(64);
  
  pcf8574Board.displayPinState();
  delay(1000);

}
