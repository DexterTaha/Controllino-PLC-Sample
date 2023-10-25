#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC209_Fast_Counter
//

//  definition of variables

int   iCount;                      // Count pulse per second
int   iLastCount=3;                // Count from last second
unsigned long previousMillis = 0;  // stored milliseconds
unsigned long currentMillis;       // actual milliseconds


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

// Interrupt handler
pinMode(CONTROLLINO_IN0, INPUT);
attachInterrupt(digitalPinToInterrupt(CONTROLLINO_IN0), count, RISING );
// LOW      to trigger the interrupt whenever the pin is low,
// CHANGE   to trigger the interrupt whenever the pin changes value
// RISING   to trigger when the pin goes from low to high,
// FALLING  for when the pin goes from high to low.

}


//
//  Loop
//
void loop() {

// current time
currentMillis = millis();

// assign iLastCount = iCount  
if ( currentMillis - previousMillis >= 1000 ) 
  {
    // each edge change triggers an interrupt
    // therefore each pulse is countes twice
    iLastCount = iCount;
    iCount = 0;
    previousMillis = currentMillis;
  }

// iLastCount > 100
if ( (iLastCount >= 100) )
    digitalWrite ( CONTROLLINO_D0, HIGH);
  else
    digitalWrite ( CONTROLLINO_D0, LOW);

// iLastCount > 200
if ( iLastCount > 200 )
    digitalWrite ( CONTROLLINO_D1, HIGH);
  else
    digitalWrite ( CONTROLLINO_D1, LOW);

// iLastCount > 300
if ( iLastCount > 300 )
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

// iLastCount > 400
if ( iLastCount > 400 )
    digitalWrite ( CONTROLLINO_D3, HIGH);
  else
    digitalWrite ( CONTROLLINO_D3, LOW);

// iLastCount > 500
if ( iLastCount > 500 )
    digitalWrite ( CONTROLLINO_D4, HIGH);
  else
    digitalWrite ( CONTROLLINO_D4, LOW);

// iLastCount > 600
if ( iLastCount > 600 )
    digitalWrite ( CONTROLLINO_D5, HIGH);
  else
    digitalWrite ( CONTROLLINO_D5, LOW);

// iLastCount > 700
if ( iLastCount > 700 )
    digitalWrite ( CONTROLLINO_D6, HIGH);
  else
    digitalWrite ( CONTROLLINO_D6, LOW);

// iLastCount > 800
if ( iLastCount > 800 )
    digitalWrite ( CONTROLLINO_D7, HIGH);
  else
    digitalWrite ( CONTROLLINO_D7, LOW);

} //loop


void count() {
 iCount++;
}




