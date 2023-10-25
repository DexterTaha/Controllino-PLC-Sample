#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC302_Counter
//

//  definition of variables

int   iCounter=0;    // counter from 0 to 7
bool  bOn;           // true-On, false-Off
bool  bFlank=LOW;   // debounce light barrier 

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);

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
  iCounter=7;

// Check if counter is under 0
if (iCounter == -1)
  iCounter=0;

// iCounter = 0
if ( iCounter == 0)
    digitalWrite ( CONTROLLINO_D0, HIGH);
  else
    digitalWrite ( CONTROLLINO_D0, LOW);

// iCounter = 1
if ( iCounter == 1) 
    digitalWrite ( CONTROLLINO_D1, HIGH);
  else
    digitalWrite ( CONTROLLINO_D1, LOW);

// iCounter = 2
if (iCounter == 2) 
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

// iCounter = 3
if (iCounter == 3) 
    digitalWrite ( CONTROLLINO_D3, HIGH);
  else
    digitalWrite ( CONTROLLINO_D3, LOW);

// iCounter = 4
if (iCounter == 4) 
    digitalWrite ( CONTROLLINO_D4, HIGH);
  else
    digitalWrite ( CONTROLLINO_D4, LOW);

// iCounter = 5
if (iCounter == 5) 
    digitalWrite ( CONTROLLINO_D5, HIGH);
  else
    digitalWrite ( CONTROLLINO_D5, LOW);

// iCounter = 6
if (iCounter == 6) 
    digitalWrite ( CONTROLLINO_D6, HIGH);
  else
    digitalWrite ( CONTROLLINO_D6, LOW);

// iCounter = 7
if (iCounter == 7) 
    digitalWrite ( CONTROLLINO_D7, HIGH);
  else
    digitalWrite ( CONTROLLINO_D7, LOW);

// adjust counter +1
if ( (bFlank == LOW )  && (digitalRead (CONTROLLINO_A0) == HIGH ) )  
  {
    iCounter++;
    bFlank = true;
  }

// adjust counter -1
if ( (bFlank == LOW )  && (digitalRead (CONTROLLINO_A1) == HIGH ) )  
  {
    iCounter--;
    bFlank = true;
  }

// set counter ot 0
if ( (bFlank == LOW )  && (digitalRead (CONTROLLINO_A2) == HIGH ) )  
  {
    iCounter=0;
    bFlank = true;
  }

// reset iFlanke bei Flankenwechsel High -> Low
if ( !(digitalRead (CONTROLLINO_A0)) && !(digitalRead (CONTROLLINO_A1)) && !(digitalRead (CONTROLLINO_A2)) )  
  {
    bFlank = false;
    delay (20);     //
  }

} //loop
