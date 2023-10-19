#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC100_AND_OR_NOT
//

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
pinMode(CONTROLLINO_A4, INPUT);
pinMode(CONTROLLINO_A6, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);

}


//
//  Loop
//
void loop() {

// AND

// 0 0    0
// 0 1    0
// 1 0    0
// 1 1    1
    
if (digitalRead (CONTROLLINO_A0 ) && digitalRead (CONTROLLINO_A1 ))
    digitalWrite (CONTROLLINO_D0 , true);
    else
    digitalWrite (CONTROLLINO_D0 , false);

// OR
    

// 0 0    0
// 0 1    1
// 1 0    1
// 1 1    1
    
if (digitalRead (CONTROLLINO_A3 ) || digitalRead (CONTROLLINO_A4 ))
    digitalWrite (CONTROLLINO_D1 , true);
    else
    digitalWrite (CONTROLLINO_D1 , false);

// NOT
    

// 0    1
// 1    0

    
if (digitalRead (CONTROLLINO_A6 ) == true )
    digitalWrite (CONTROLLINO_D2 , false);
    else
    digitalWrite (CONTROLLINO_D2 , true);
} 
