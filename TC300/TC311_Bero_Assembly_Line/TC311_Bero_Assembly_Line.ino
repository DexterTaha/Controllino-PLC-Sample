#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC311_Bero_Assembly_Line
//

//  definition of variables

bool  bOn;                          // On / Off
bool  bRunLeft;                     // run to left side
bool  bRunRight;                    // run to right side
int   iCount;                       // Count pulse current second
int   iLastCount=3;                 // Count from last second
unsigned long previousMillis = 0;   // stored milliseconds
unsigned long currentMillis;        // actual milliseconds

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
attachInterrupt(digitalPinToInterrupt(CONTROLLINO_IN0), count, RISING);
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

// On / Off
if ( digitalRead (CONTROLLINO_A0) )
    bOn = true;
  else
    bOn = false;
  

// detect run right side
if ( iLastCount < 300 ) 
  {
    bRunLeft = false;
    bRunRight = true;
  }

// Detect run left side
if ( iLastCount > 700 ) 
  {
    bRunLeft = true;
    bRunRight = false;
  }

// start motor in required direction

if ( bRunLeft && bOn ) 
  {
    digitalWrite ( CONTROLLINO_D3, LOW);
    digitalWrite ( CONTROLLINO_D2, HIGH);
  }
  else if ( bRunRight && bOn ) 
  {
    digitalWrite ( CONTROLLINO_D2, LOW);
    digitalWrite ( CONTROLLINO_D3, HIGH);
  }
  else if (!bOn)
  {
    digitalWrite ( CONTROLLINO_D2, LOW);
    digitalWrite ( CONTROLLINO_D3, LOW);
  }

} //loop


void count() {
 iCount++;
}



