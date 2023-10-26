#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC306_Empties_automat
//

//  definition of variables

bool bOn;                   // automat ON/OFF

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
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

// On / Off
if ( digitalRead (CONTROLLINO_A0) )
    bOn = true;
  else
    bOn = false;
  
// Start process with barrier sensor
if ( digitalRead(CONTROLLINO_A1) && bOn ) 
  {
    // start assembly line 1 
    // wait until light barrier sensor 2 detects bottle
    while ( digitalRead (CONTROLLINO_A2) == LOW )
    {
      digitalWrite ( CONTROLLINO_D0, HIGH);
    }
    // stop assembly line 1 
    digitalWrite ( CONTROLLINO_D0, LOW);
    // start bar code scanner until code is read
    while ( digitalRead (CONTROLLINO_A3) == LOW )
    {
      digitalWrite ( CONTROLLINO_D1, HIGH);
    }
    // stop bar code scanner
    digitalWrite ( CONTROLLINO_D1, LOW);
    // start assembly line 2 
    // wait until light barrier sensor 3 detects bottle
    while ( digitalRead (CONTROLLINO_A5) == LOW )
    {
      digitalWrite ( CONTROLLINO_D2, HIGH);
    }
    // stop assembly line 2
    digitalWrite ( CONTROLLINO_D2, LOW);
    // start bottle press
    digitalWrite ( CONTROLLINO_D3, HIGH);
    // time to press bottle
    delay (5000);
    // stop bottle press
    digitalWrite ( CONTROLLINO_D3, LOW);
    // start assembly line 2 
    // wait until light barrier sensor 3 detects bottle
    while ( digitalRead (CONTROLLINO_A5) == HIGH )
    {
      digitalWrite ( CONTROLLINO_D2, HIGH);
    }
    // stop assembly line 2
    digitalWrite ( CONTROLLINO_D2, LOW);
  }

} //loop
