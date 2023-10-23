#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC200_Nurse_call
//

//  definition of variables

bool bAlarm = false;

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
pinMode(CONTROLLINO_A5, INPUT);
pinMode(CONTROLLINO_A7, INPUT);

pinMode(CONTROLLINO_D2, OUTPUT);

}

//
//  Loop
//
void loop() {

// Resetting ALARM 
if (digitalRead (CONTROLLINO_A1)==true ) 
    bAlarm=false;

// Set Alarm 
if ((digitalRead (CONTROLLINO_A3)==true ) || (digitalRead(CONTROLLINO_A5)==true ) || (digitalRead(CONTROLLINO_A7)==true ))
    bAlarm=true;

// Output ALARM
digitalWrite (CONTROLLINO_D2,bAlarm);

} //loop
