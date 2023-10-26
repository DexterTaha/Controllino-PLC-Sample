#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC310_Awning_control
//

//  definition of variables

bool bAuto;           // Automatic mode-true, manuell mode-false
bool bOpening;        // opening manually
bool bClosing;       // closing manually
bool bEndOpen;        // end switch open
bool bEndClose;       // end switch closed
int  iWind;           // analog value windy
int  iBrightness;     // analog value brightness

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
pinMode(CONTROLLINO_A4, INPUT);
pinMode(CONTROLLINO_A6, INPUT);
pinMode(CONTROLLINO_A7, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);

}


//
//  Loop
//
void loop() {

// Read analog values from wind- and brightness sensor
iBrightness = analogRead (CONTROLLINO_A6);
iWind = analogRead (CONTROLLINO_A7);


// detect automatic mode
if ( digitalRead (CONTROLLINO_A0) )
    bAuto = true;
  else
    bAuto = false;

// detect End Switch opened
if ( digitalRead (CONTROLLINO_A3) ) 
  {
    bEndOpen = true;
  }
  else
  {
    bEndOpen = false;
  }

// detect End Switch Closed
if ( digitalRead (CONTROLLINO_A4) ) 
  {
    bEndClose = true;
  }
  else
  {
    bEndClose = false;
  }

// switch manuelly opening
if ( digitalRead (CONTROLLINO_A1) ) 
  {
    bOpening = true;
  }
  else
  {
    bOpening = false;
  }

// switch manuelly closing
if ( digitalRead (CONTROLLINO_A2) ) 
  {
    bClosing = true;
  }
  else
  {
    bClosing = false;
  }

// Automatic-, manuell mode
if (bAuto)
  {
    // Automatic mode
    // Open if no wind but sun
    if ( (iWind<150) && (iBrightness>150) )
      {
        bOpening = true;
        bClosing = false;
      }
    
    // Close if wind
    if ( iWind>150 )
      {
        bClosing = true;
        bOpening = false;
      }

    // Close if no brightness
    if ( iBrightness<150 )
      {
        bClosing = true;
        bOpening = false;
      }
  }
  else
  {
    // Manuell mode
    // Close if wind
    if ( iWind>150 )
      {
        bClosing = true;
        bOpening = false;
      }
  }

// if both open and close 
if ( bOpening && bClosing ) 
  {
    bClosing = true;
    bOpening = false;
  }
  
// Motor control 
if ( bOpening && !bEndOpen ) 
  {
    digitalWrite ( CONTROLLINO_D3, LOW);
    digitalWrite ( CONTROLLINO_D2, HIGH);
  }
  else if ( bClosing && !bEndClose ) 
  {
    digitalWrite ( CONTROLLINO_D2, LOW);
    digitalWrite ( CONTROLLINO_D3, HIGH);
  }
  else
  {
    digitalWrite ( CONTROLLINO_D2, LOW);
    digitalWrite ( CONTROLLINO_D3, LOW);
  }

// Signaling open 
if ( bEndOpen ) 
    digitalWrite ( CONTROLLINO_D0, HIGH);
  else 
    digitalWrite ( CONTROLLINO_D0, LOW);

// Signaling closed 
if ( bEndClose ) 
    digitalWrite ( CONTROLLINO_D1, HIGH);
  else 
    digitalWrite ( CONTROLLINO_D1, LOW);

} //loop
