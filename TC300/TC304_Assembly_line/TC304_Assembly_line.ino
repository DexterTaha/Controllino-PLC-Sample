#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC304_Assembly_line
//

//  definition of variables

bool bOn;         // true-on, false-off
bool bRunLeft;    // run to left side
bool bRunRight;   // run to right side
bool bEmergency;  // true-on, false-off

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
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

// On / Off
if ( digitalRead (CONTROLLINO_A0) )
    bOn = true;
  else
    bOn = false;
  

// detect run left side
if ( digitalRead (CONTROLLINO_A2) ) 
  {
    bRunLeft = true;
    bRunRight = false;
  }

// Detect run right side
if ( digitalRead (CONTROLLINO_A6) ) 
  {
    bRunRight = true;
    bRunLeft = false;
  }

// Reset Emergency
if ( digitalRead (CONTROLLINO_A4) ) 
  {
    bEmergency = false;
    bRunRight = false;
    bRunLeft = false;
  }

// Detect Emergency or failure run in both directions at same time
if ( !digitalRead (CONTROLLINO_A3) || (bRunLeft && bRunRight) ) 
  {
    bEmergency = true;
  }

// select motor direction
if ( bRunLeft && !bEmergency && bOn ) 
  {
    digitalWrite ( CONTROLLINO_D0, LOW);
    digitalWrite ( CONTROLLINO_D1, HIGH);
  }
  else 
  {
    if ( bRunRight && !bEmergency && bOn ) 
    {
      digitalWrite ( CONTROLLINO_D1, LOW);
      digitalWrite ( CONTROLLINO_D0, HIGH);
    }
    else
    {
      digitalWrite ( CONTROLLINO_D1, LOW);
      digitalWrite ( CONTROLLINO_D0, LOW);
    }
  }
  
// Signaling Emergency
if ( bEmergency ) 
  {
    digitalWrite ( CONTROLLINO_D2, HIGH);
  }
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

} //loop
