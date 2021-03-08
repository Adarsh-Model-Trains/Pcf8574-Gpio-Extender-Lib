# Pcf8574

---

# <a href="https://github.com/adarshkumarsingh83/Pcf8574-lib/archive/main.zip">download</a>

## About the Lib
```
Pcf8574-lib is for supporing multiple Pcf8574 boards together 
in chain with less complexcity of the programming 

mex we can connect 8 Pcf8574 together in chain which will give extra 64 pins for operations 
this api support a simple interface where we can controll 0-63 pins by its sequence number 
respected to their sequence in the chain 

pin number will start from 1 to (number of board X 8 pin per board)

NOTE: pcf8574 work on different logic so when pin is low by current then its on and when pin is high then its off 
but that is taken care by on off api already 

``` 

## addressing 
![img](/image/PCF8574-ADDRESS-CONFIG.png)
```
for different adddress configuation we have to set the jumper of Pcf8574 board like shown in the above image 
and we can set 8 boareds with 0x21 to 0x27 addressing with 8pin in each board
```

## steps for using lib

### include the headfile 
```
#include "Pcf8574.h"
#include "Pcf8574Board.h"
```


### define the pointer for the Pcf8574Board
```
Pcf8574Board *pcf8574Board;
```

### define the number of the board we are using in chain 
```
#define NO_OF_BOARDS 8
```

### initialize the pointer with obuject in setup method 
```
void setup() {
  
   .....

    pcf8574Board = &Pcf8574Board(NO_OF_BOARDS);
  
  .......

}

```

### for debug messages a initialize Serial in setup 


```
void setup() {
  
  Serial.begin(xxxx); // xxx can be any valid supported number 
  pcf8574Board = &Pcf8574Board(NO_OF_BOARDS);

  .........
}

```

### use lib method for pin on 
* NOTE WE ARE USING POINTER SO WE HAVE TO USE -> MARK FOR CALLING METHODS 
```
void loop() {
  
  .......

  pcf8574Board-> switchOn(pinNo); // pinNo is the sequence value of the pin in Pcf8574 chain starting from 0 to (8 x number of board) in chain 
  
  ..........
}

```

### use lib method for pin off

* NOTE WE ARE USING POINTER SO WE HAVE TO USE -> MARK FOR CALLING METHODS 

```
void loop() {
  
  .......

  pcf8574Board-> switchOn(pinNo); // pinNo is the sequence value of the pin in Pcf8574 chain starting from 0 to (8 x number of board) in chain 
  
  ..........
}
```


## Complete Example 
```
#include "Pcf8574.h"
#include "Pcf8574Board.h"

Pcf8574Board *pcf8574Board;

#define NO_OF_BOARDS 5
int MAX_PINS = 0;
void setup() {
  Serial.begin(9600);
  pcf8574Board = &Pcf8574Board(NO_OF_BOARDS);
  MAX_PINS = NO_OF_BOARDS * 8;
}

void loop() {
  int pinNo = random(0, MAX_PINS);
  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  Serial.print("PIN NO ");
  Serial.println(pinNo);
  delay(1000);
  pcf8574Board-> switchOn(pinNo);
  pcf8574Board->displayPinState();
  delay(1000);
  pcf8574Board->switchOff(pinNo);
  pcf8574Board->displayPinState();
  delay(1000);
}

```

