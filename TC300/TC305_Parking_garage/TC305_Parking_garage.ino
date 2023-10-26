#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC305_Parking_garage
//

//  definition of variables

bool bRequestDriveIn;           // request, drive into the garage
bool bRequestDriveOut;          // request, drive out of the garage
bool bEndSwitchOpen;            // end switch, garage door open
bool bEndSwitchClosed;          // end switch, garage door closed

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
pinMode(CONTROLLINO_A6, INPUT);
pinMode(CONTROLLINO_A7, INPUT);

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

// detect request drive in
if ( digitalRead (CONTROLLINO_A0) ) 
  {
    bRequestDriveIn = true;
  }

// detect request drive out
if ( digitalRead (CONTROLLINO_A6) ) 
  {
    bRequestDriveOut = true;
  }

// process open door for drive in
if ( bRequestDriveIn ) 
  {
    // switch traffic light to RED
    digitalWrite ( CONTROLLINO_D0, HIGH);
    digitalWrite ( CONTROLLINO_D3, HIGH);
    delay (1000);
    // start open door
    while ( digitalRead (CONTROLLINO_A3) == LOW )
    {
      digitalWrite ( CONTROLLINO_D1, HIGH);
    }
    // stop opening door
    digitalWrite ( CONTROLLINO_D1, LOW);
    delay (1000);
    // remove RED traffic light for entrance 
    digitalWrite ( CONTROLLINO_D0, LOW);
    // time to drive in
    delay (5000);
    // Set again RED traffic light for entrance 
    digitalWrite ( CONTROLLINO_D0, HIGH);
    delay (2000);
    // start close door
    while ( digitalRead (CONTROLLINO_A4) == LOW )
    {
      digitalWrite ( CONTROLLINO_D2, HIGH);
    }
    // stop closing door
    digitalWrite ( CONTROLLINO_D2, LOW);
    delay (1000);
    // switch off traffic light
    digitalWrite ( CONTROLLINO_D0, LOW);
    digitalWrite ( CONTROLLINO_D3, LOW);
    // Set back request for drive in
    bRequestDriveIn = false;
  }

// process open door for drive out
if ( bRequestDriveOut ) 
  {
    // switch traffic light to RED
    digitalWrite ( CONTROLLINO_D0, HIGH);
    digitalWrite ( CONTROLLINO_D3, HIGH);
    delay (1000);
    // start open door
    while ( digitalRead (CONTROLLINO_A3) == LOW )
    {
      digitalWrite ( CONTROLLINO_D1, HIGH);
    }
    // stop opening door
    digitalWrite ( CONTROLLINO_D1, LOW);
    delay (1000);
    // remove RED traffic light for exiting 
    digitalWrite ( CONTROLLINO_D3, LOW);
    // time to drive out
    delay (5000);
    // Set again RED traffic light for exiting 
    digitalWrite ( CONTROLLINO_D3, HIGH);
    delay (2000);
    // start close door
    while ( digitalRead (CONTROLLINO_A4) == LOW )
    {
      digitalWrite ( CONTROLLINO_D2, HIGH);
    }
    // stop closing door
    digitalWrite ( CONTROLLINO_D2, LOW);
    delay (1000);
    // switch off traffic light
    digitalWrite ( CONTROLLINO_D0, LOW);
    digitalWrite ( CONTROLLINO_D3, LOW);
    // Set back request for drive out
    bRequestDriveOut = false;
  }


} //loop
