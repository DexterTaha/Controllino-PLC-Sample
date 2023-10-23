#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC202_Lifting_ramp
//

//  definition of variables

bool bOn;           // Lifting ramp ON
bool bStepUp;       // move up
bool bStepDown;     // move down
bool bEndUp;        // reached top level
bool bEndDown;      // reached bottom level

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A4, INPUT);
pinMode(CONTROLLINO_A5, INPUT);

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

// detect End Switch up side
if ( digitalRead (CONTROLLINO_A4) ) 
  {
    bEndUp = true;
  }
  else
  {
    bEndUp = false;
  }

// detect End Switch down side
if ( digitalRead (CONTROLLINO_A5) ) 
  {
    bEndDown = true;
  }
  else
  {
    bEndDown = false;
  }

// move up
if ( digitalRead (CONTROLLINO_A1) && !bEndUp  && bOn) 
  {
    bStepUp = true;
  }
  else
  {
    bStepUp = false;
  }

// move down
if ( digitalRead (CONTROLLINO_A2) && !bEndDown && bOn) 
  {
    bStepDown = true;
  }
  else
  {
    bStepDown = false;
  }

// switch on motor
if ( bStepUp && !bStepDown ) 
  {
    digitalWrite ( CONTROLLINO_D3, LOW);
    digitalWrite ( CONTROLLINO_D2, HIGH);
  }
  else 
  { if ( bStepDown && !bStepUp ) 
    {
      digitalWrite ( CONTROLLINO_D2, LOW);
      digitalWrite ( CONTROLLINO_D3, HIGH);
    }
    else
    {
      digitalWrite ( CONTROLLINO_D2, LOW);
      digitalWrite ( CONTROLLINO_D3, LOW);
    }
  }

} //loop
