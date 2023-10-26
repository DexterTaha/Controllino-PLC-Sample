#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC310_Awning_control
//

//  definition of variables

bool bOn;             // Automatic mode-true, manuell mode-false
bool bThermCutOff;    // switch overtemperature
int  iTempBoiler;     // actual temperature boler
int  iTempRoom;       // actual temperature room

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
pinMode(CONTROLLINO_D3, OUTPUT);

}


//
//  Loop
//
void loop() {

// Read analog values from wind- and lightsensor
iTempRoom = analogRead (CONTROLLINO_A6);
iTempBoiler = analogRead (CONTROLLINO_A7);

// detect on / off
if ( digitalRead (CONTROLLINO_A0) )
    bOn = true;
  else
    bOn = false;

// detect RESET termal cut-off boiler
if ( digitalRead (CONTROLLINO_A1) ) 
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

// Pump for room heating on/off
if ( (iTempRoom<100) && !bThermCutOff && bOn)
  {
    digitalWrite (CONTROLLINO_D3, HIGH);
  }
  else
  {
    digitalWrite (CONTROLLINO_D3, LOW);
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
