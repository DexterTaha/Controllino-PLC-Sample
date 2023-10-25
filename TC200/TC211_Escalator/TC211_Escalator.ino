#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC211_Escalator
//

//  definition of variables

bool  bOn=false;                       // true-On, false-Off
bool  bEmergency;                      // true-emergency, false-OK
bool  bBeltFailure;                    //true-failure, false-OK
const long iEscalatorRunning = 5000;   // delay until escalater stops
unsigned long previousMillis = 0;      // stored milliseconds
unsigned long currentMillis;           // actual milliseconds


//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A4, INPUT);
pinMode(CONTROLLINO_A6, INPUT);
pinMode(CONTROLLINO_A7, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);
}


//
//  Loop
//
void loop() {

currentMillis = millis();

// Button escalator On
if ( digitalRead ( CONTROLLINO_A0 ) == HIGH )
    bOn = true;
  else
    bOn=false;

// Reset emergency
if ( digitalRead ( CONTROLLINO_A4 ) == HIGH )
    bEmergency = false;

// Check for emergency -> normally closed
if ( (digitalRead ( CONTROLLINO_A1 ) == LOW) || (digitalRead ( CONTROLLINO_A7 ) == LOW))
    bEmergency = true;

// Detect belt failure -> normally closed
if ( digitalRead ( CONTROLLINO_A6 ) == LOW )
    {
      bBeltFailure = true;
      bEmergency = true;
    }
  else
    bBeltFailure = false;

// Start escalator with lighning barrier
if ( bOn && !bEmergency && (digitalRead ( CONTROLLINO_A2 ) == HIGH) )
  {
    digitalWrite ( CONTROLLINO_D3, HIGH);
    previousMillis = currentMillis;
  }

// Stop escalator on emergency or delay ends
if ( bEmergency || (currentMillis - previousMillis >= iEscalatorRunning) )
  digitalWrite ( CONTROLLINO_D3, LOW);

// Signaling ALARM
if ( bEmergency )
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

// Signaling Escalator On
if ( bOn )
    digitalWrite ( CONTROLLINO_D0, HIGH);
  else
    digitalWrite ( CONTROLLINO_D0, LOW);
 
} //loop
