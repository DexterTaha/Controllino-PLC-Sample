#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC308_Heating_living_room
//

//  definition of variables

int  iTempIs;     // actual room temperature
int  iTempSet;    // required room temperature

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

// Read analog values from wind- and lightsensor
iTempIs = analogRead (CONTROLLINO_A6);
iTempSet = analogRead (CONTROLLINO_A7);

// Pump for room heating on/off
if ( iTempIs < iTempSet )
  {
    digitalWrite (CONTROLLINO_D3, HIGH);
  }
  else
  {
    digitalWrite (CONTROLLINO_D3, LOW);
  }
  
} //loop
