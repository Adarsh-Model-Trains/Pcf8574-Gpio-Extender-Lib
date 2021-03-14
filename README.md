# Pcf8574-Gpio-Extender-Lib

---

# <a href="https://github.com/adarshkumarsingh83/Pcf8574-lib/archive/main.zip"> Library download link </a>

## About the Lib
```
Pcf8574-Gpio-Extender-Lib is for supporing multiple Pcf8574 boards together 
in chain with less complexcity of the programming 

mex we can connect 8 Pcf8574 together in chain which will give extra 64 pins for operations 
this api support a simple interface where we can controll 1-64 pins by its sequence number 
respected to their sequence in the chain 

pin number will start from 1 to (number of board X 8 pin per board)

NOTE: pcf8574 work on different logic so when pin is low by current then its on and when pin is high then its off 
but that is taken care by on off api already 

NOTE: Order of Pcf8574 board address wise must be in sequence otherwise it will not work in expected manner 

``` 

## connections details 

![img](/image/connections.JPG)
```
Connect Details 
we have connect the sda and scl from arduino to Pcf8574 board 
+5v vcc and gnd pin from arduino to Pcf8574 board 
then connect the device on pin po to p7 for controlling them 
use the vcc of the last board for powering up the device 

```


## addressing 
![img](/image/PCF8574-ADDRESS-CONFIG.png)
```
for different adddress configuation we have to set the jumper of Pcf8574 board like shown in the above image 
and we can set 8 boareds with 0x21 to 0x27 addressing with 8pin in each board
```

## steps for using lib

### include the header file 
```
#include "Pcf8574.h"
#include "Pcf8574Board.h"
```


### define the object for the Pcf8574Board
```
Pcf8574Board pcf8574Board;
```

### define the number of the board we are using in chain 
```
#define NO_OF_BOARDS 8
```


### initialize the Pcf8574Boards object for using its methods 
* initPcf8574Boards(NO_OF_BOARDS) will take no of Pcf8574 boards we want to configure in chain max 8 boards 
```
    .......
      pcf8574Board.initPcf8574Boards(NO_OF_BOARDS);
     ........
```


### for debug messages a initialize Serial in setup 
```
void setup() {
  
  Serial.begin(xxxx); // xxx can be any valid supported number 

  .........
}

```

### use lib method for pin on 
* switchOn(pinNo) will take the pin number 1 to ( no of boards X 8 ) in chain sequence 
```
void loop() {
  
  .......

  pcf8574Board.switchOn(pinNo); // pinNo is the sequence value of the pin in Pcf8574 chain starting from 0 to (8 x number of board) in chain 
  
  ..........
}

```

### use lib method for pin off
* switchOn(pinNo) will take the pin number 1 to ( no of boards X 8 ) in chain sequence 
```
void loop() {
  
  .......

  pcf8574Board.switchOn(pinNo); // pinNo is the sequence value of the pin in Pcf8574 chain starting from 0 to (8 x number of board) in chain 
  
  ..........
}
```


## Complete Example 
```
#include "Pcf8574.h"
#include "Pcf8574Board.h"

#define NO_OF_BOARDS 5

Pcf8574Board pcf8574Board;
int MAX_PINS = 0;

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

```

