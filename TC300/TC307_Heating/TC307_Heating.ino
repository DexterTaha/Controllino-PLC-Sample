#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC307_Heating

//  definition of variables

bool bOn;           // Automatic mode-true, manuell mode-false
bool bThermCutOff;  // switch boiler overtemperature
int  iTempBoiler;   // Analog sensor boiler temperature

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
pinMode(CONTROLLINO_A4, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);

}


//
//  Loop
//
void loop() {

// Read analog values from wind- and lightsensor
iTempBoiler = analogRead (CONTROLLINO_A7);

// detect on / off
if ( digitalRead (CONTROLLINO_A0) )
    bOn = true;
  else
    bOn = false;

// detect RESET termal cut-off boiler
if ( digitalRead (CONTROLLINO_A4) ) 
  {
    bThermCutOff = false;
  }

// detect termalcut-off boiler
if ( !digitalRead (CONTROLLINO_A3) ) 
  {
    bThermCutOff = true;
  }

// Heating torch on/off
if ( (iTempBoiler<200) && !bThermCutOff && bOn)
  {
    digitalWrite (CONTROLLINO_D1, HIGH);
  }
  else
  {
    digitalWrite (CONTROLLINO_D1, LOW);
  }

// Signaling Heating on
if ( bOn )
  {
    digitalWrite (CONTROLLINO_D0, HIGH);
  }
  else
  {
    digitalWrite (CONTROLLINO_D0, LOW);
  }

// Signaling ALARM
if ( bThermCutOff )
  {
    digitalWrite (CONTROLLINO_D2, HIGH);
  }
  else
  {
    digitalWrite (CONTROLLINO_D2, LOW);
  }
  
} //loop
