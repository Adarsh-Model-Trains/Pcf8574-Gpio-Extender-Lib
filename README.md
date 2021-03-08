# Pcf8574

---

## About the Lib
```
Pcf8574-lib is for supporing multiple Pcf8574 boards together 
in chain with less complexcity of the programming 

mex we can connect 8 Pcf8574 together in chain which will give extra 64 pins for operations 
this api support a simple interface where we can controll 0-63 pins by its sequence number 
respected to their sequence in the chain 

pin number will start from 1 to (number of board X 8 pin per board)

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
```
void loop() {
  
  .......

  pcf8574Board-> switchOn(pinNo); // pinNo is the sequence value of the pin in Pcf8574 chain starting from 0 to (8 x number of board) in chain 
  
  ..........
}

```

### use lib method for pin off
```
void loop() {
  
  .......

  pcf8574Board-> switchOn(pinNo); // pinNo is the sequence value of the pin in Pcf8574 chain starting from 0 to (8 x number of board) in chain 
  
  ..........
}
```


