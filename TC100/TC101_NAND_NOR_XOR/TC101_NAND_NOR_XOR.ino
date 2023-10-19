#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC101_NAND_NOR_XOR
//

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
pinMode(CONTROLLINO_A4, INPUT);
pinMode(CONTROLLINO_A5, INPUT);
pinMode(CONTROLLINO_A6, INPUT);
pinMode(CONTROLLINO_A7, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);
pinMode(CONTROLLINO_D4, OUTPUT);
pinMode(CONTROLLINO_D5, OUTPUT);
pinMode(CONTROLLINO_D6, OUTPUT);
pinMode(CONTROLLINO_D7, OUTPUT);

}


//
//  Loop
//
void loop() {

// NAND

// 0 0    1
// 0 1    1
// 1 0    1
// 1 1    0

if (digitalRead (CONTROLLINO_A0 ) && digitalRead (CONTROLLINO_A1 ))
    digitalWrite (CONTROLLINO_D0 , false);
    else
    digitalWrite (CONTROLLINO_D0 , true);

// NOR

// 0 0    1
// 0 1    0
// 1 0    0
// 1 1    0

if (!digitalRead (CONTROLLINO_A3 ) && !digitalRead (CONTROLLINO_A4 ))
    digitalWrite (CONTROLLINO_D1 , true);
    else
    digitalWrite (CONTROLLINO_D1 , false);

// XOR

// 0 0    0
// 0 1    1
// 1 0    1
// 1 1    0

if ((digitalRead (CONTROLLINO_A5 ) && !digitalRead (CONTROLLINO_A6 )) || (!digitalRead (CONTROLLINO_A5 ) && digitalRead (CONTROLLINO_A6 )))
    digitalWrite (CONTROLLINO_D2 , true);
    else
    digitalWrite (CONTROLLINO_D2 , false);
} 

