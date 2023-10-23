#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC104_Pulse_generator
//

//  definition of variables

int  iDelay=200;

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);

}

//
//  Loop
//
void loop() {

// Pulse_generator

if (digitalRead (CONTROLLINO_A0 ))
     {
        digitalWrite (CONTROLLINO_D0, true);
        delay (iDelay);
        digitalWrite (CONTROLLINO_D0, false);
        delay (iDelay);
     }

} //loop
