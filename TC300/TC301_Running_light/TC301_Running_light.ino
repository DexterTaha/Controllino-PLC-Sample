#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC301_Running_light
//

//  definition of variables

int   iCounter=0;    // counter  0 to 7
bool  bOn;           // true-On, false-Off
bool  bDirection;    // false-right, true-left


//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);
pinMode(CONTROLLINO_D4, OUTPUT);
pinMode(CONTROLLINO_D5, OUTPUT);
pinMode(CONTROLLINO_D6, OUTPUT);
pinMode(CONTROLLINO_D7, OUTPUT);

}


//
//  Loop
//
void loop() {

// Check if counter is over 7
if (iCounter == 8)
  iCounter=0;

// Check if counter is under 0
if (iCounter == -1)
  iCounter=7;

// counter on/off
if ( digitalRead (CONTROLLINO_A0) == HIGH ) 
    bOn = true;
  else
    bOn = false;

// counter directorn
if ( digitalRead (CONTROLLINO_A1) == HIGH )
    bDirection = true;
  else
    bDirection = false;

// iCounter = 0
if ( bOn && (iCounter == 0) )
    digitalWrite ( CONTROLLINO_D0, HIGH);
  else
    digitalWrite ( CONTROLLINO_D0, LOW);

// iCounter = 1
if ( bOn && (iCounter == 1) )
    digitalWrite ( CONTROLLINO_D1, HIGH);
  else
    digitalWrite ( CONTROLLINO_D1, LOW);

// iCounter = 2
if ( bOn && (iCounter == 2) )
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

// iCounter = 3
if ( bOn && (iCounter == 3) )
    digitalWrite ( CONTROLLINO_D3, HIGH);
  else
    digitalWrite ( CONTROLLINO_D3, LOW);

// iCounter = 4
if ( bOn && (iCounter == 4) )
    digitalWrite ( CONTROLLINO_D4, HIGH);
  else
    digitalWrite ( CONTROLLINO_D4, LOW);

// iCounter = 5
if ( bOn && (iCounter == 5) )
    digitalWrite ( CONTROLLINO_D5, HIGH);
  else
    digitalWrite ( CONTROLLINO_D5, LOW);

// iCounter = 6
if ( bOn && (iCounter == 6) )
    digitalWrite ( CONTROLLINO_D6, HIGH);
  else
    digitalWrite ( CONTROLLINO_D6, LOW);

// iCounter = 7
if ( bOn && (iCounter == 7) )
    digitalWrite ( CONTROLLINO_D7, HIGH);
  else
    digitalWrite ( CONTROLLINO_D7, LOW);

delay (500);

// Set new iCounter value
if (bDirection == false )
    iCounter++;
  else
    iCounter--;

} //loop
