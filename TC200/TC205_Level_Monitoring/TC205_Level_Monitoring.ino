#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC205_Level_Monitoring
//

//  definition of variables

bool  bFilling=false;    // true-On, false-Off

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

// push button On
if ( digitalRead ( CONTROLLINO_A0 ) == HIGH )
    bFilling = true;

// push button Off
if ( digitalRead ( CONTROLLINO_A1 ) == LOW )
    bFilling = false;

// Start Pump1 til 100%
if ( bFilling && digitalRead (CONTROLLINO_A7)==LOW)
  {
    digitalWrite ( CONTROLLINO_D0, HIGH);
  }
  else
  {
    digitalWrite ( CONTROLLINO_D0, LOW);
    bFilling=false;
  }

// Start Pump2 til 80%
if ( bFilling && digitalRead (CONTROLLINO_A6)==LOW)
  {
    digitalWrite ( CONTROLLINO_D1, HIGH);
  }
  else
  {
    digitalWrite ( CONTROLLINO_D1, LOW);
  }

// Signaling <10%
if ( digitalRead (CONTROLLINO_A5)==LOW)
  {
    digitalWrite ( CONTROLLINO_D3, HIGH);
  }
  else
  {
    digitalWrite ( CONTROLLINO_D3, LOW);
  }

} //loop
