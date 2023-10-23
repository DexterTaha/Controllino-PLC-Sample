#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC106_Logical_connection
//

//  definition of variables

bool bAND;
bool bOR;
bool bNOT;

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A3, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);

}

//
//  Loop
//
void loop() {

// Logical_connection

if ((digitalRead (CONTROLLINO_A0)==true ) && (digitalRead(CONTROLLINO_A1)==true ))
    bAND=true;
  else
    bAND=false;
digitalWrite (CONTROLLINO_D0,bAND);

if ((digitalRead (CONTROLLINO_A3)==true ) || bAND)
    bOR=true;
  else
    bOR=false;
digitalWrite (CONTROLLINO_D1,bOR);

bNOT = !bOR;
digitalWrite (CONTROLLINO_D2,bNOT);

} //loop
