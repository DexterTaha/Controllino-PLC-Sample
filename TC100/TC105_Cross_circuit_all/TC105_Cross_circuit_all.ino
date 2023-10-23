#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC105_Cross_circuit
//

//  definition of variables

int  iDelay=200;
bool bStatus;
bool bToggle;

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

// Cross_circuit

if (digitalRead (CONTROLLINO_A0 ) && (bToggle==false) )
     {
        bStatus=!bStatus;
        bToggle=true;
     }
if (digitalRead (CONTROLLINO_A1 ) && (bToggle==false) )
     {
        bStatus=!bStatus;
        bToggle=true;
     }
digitalWrite (CONTROLLINO_D0,bStatus);
if ((digitalRead (CONTROLLINO_A0)==false ) && (digitalRead(CONTROLLINO_A1)==false ))
  bToggle=false;

delay (50);

} //loop
