#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC303_Crane
//

//  definition of variables

bool bOn;           // true-on,  false-off
bool bStepUp;       // lift load
bool bStepDown;     // unload
bool bEndTop;       // top reached
bool bEmergency;    // emergency-true
bool bLoadToHigh;   // load is to high
int iCraneLoad;     // analog load value on the winch

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

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);

}


//
//  Loop
//
void loop() {

// Read the analog load value on the winch
iCraneLoad = analogRead (CONTROLLINO_A7);

// On / Off
if ( digitalRead (CONTROLLINO_A0) )
    bOn = true;
  else
    bOn = false;
  

// detect winch on top
if ( digitalRead (CONTROLLINO_A3) ) 
  {
    bEndTop = true;
  }
  else
  {
    bEndTop = false;
  }

// Detect step Up
if ( digitalRead (CONTROLLINO_A1) && !bEndTop) 
  {
    bStepUp = true;
  }
  else
  {
    bStepUp = false;
  }

// Detect step Down
if ( digitalRead (CONTROLLINO_A2) ) 
  {
    bStepDown = true;
  }
  else
  {
    bStepDown = false;
  }

// Reset Emergency
if ( digitalRead (CONTROLLINO_A4) || (iCraneLoad > 600) ) 
  {
    bEmergency = false;
  }

// Detect Emergency
if ( !digitalRead (CONTROLLINO_A5) ) 
  {
    bEmergency = true;
  }

// Detect high load
if ( iCraneLoad > 200 ) 
  {
    bLoadToHigh = true;
  }
  else 
  {
    bLoadToHigh = false;
  }

if ( bStepUp && !bEmergency && !bLoadToHigh && bOn ) 
  {
    digitalWrite ( CONTROLLINO_D1, LOW);
    digitalWrite ( CONTROLLINO_D0, HIGH);
  }
  else 
  {
    if ( bStepDown && !bEmergency && bOn ) 
    {
    digitalWrite ( CONTROLLINO_D0, LOW);
    digitalWrite ( CONTROLLINO_D1, HIGH);
    }
    else
    {
      digitalWrite ( CONTROLLINO_D0, LOW);
      digitalWrite ( CONTROLLINO_D1, LOW);
    }
  }

// Signaling Crane On
if ( bOn ) 
    digitalWrite ( CONTROLLINO_D3, HIGH);
  else
    digitalWrite ( CONTROLLINO_D3, LOW);

// Signaling Emergency
if ( bEmergency || bLoadToHigh ) 
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

} //loop
