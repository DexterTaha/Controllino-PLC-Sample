#include <Controllino.h>
#include <SPI.h>

//
//  Task: TC103_Switch_on-off_delay
//

//  definition of variables

int  iDelay=1000;


//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
pinMode(CONTROLLINO_A5, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);

}


//
//  Loop
//
void loop() {

// Switch_on_delay

if (digitalRead (CONTROLLINO_A0 ))
     {
        delay (iDelay);
        digitalWrite (CONTROLLINO_D0, true);
     }
   else
    digitalWrite (CONTROLLINO_D0, false);

// Switch_off_delay

if (digitalRead (CONTROLLINO_A3 ))
     {
        digitalWrite (CONTROLLINO_D1, true);
     }
   else
     {
        delay (iDelay);
        digitalWrite (CONTROLLINO_D1, false);
     }
    
if (digitalRead (CONTROLLINO_A5 ))
     {
        delay (iDelay);
        digitalWrite (CONTROLLINO_D2, true);
     }
   else
     {
        delay (iDelay);
        digitalWrite (CONTROLLINO_D2, false);
     }


} //loop
