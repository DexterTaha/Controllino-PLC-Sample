#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC201_Corridor_Light
//

//  definition of variables

int   iValueIs;    // analog value
int   iValueSet;    // analog value

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

// Read fuel level from analog Sensor
iValueIs = analogRead ( CONTROLLINO_A6 );
iValueSet = analogRead ( CONTROLLINO_A7 );

// iValueIs < iValueSet
if ( (iValueIs < iValueSet-20) )
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D1, LOW);

// iValueIs < iValueSet
if ( (iValueIs > iValueSet+200) )
    digitalWrite ( CONTROLLINO_D1, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

    
} //loop
