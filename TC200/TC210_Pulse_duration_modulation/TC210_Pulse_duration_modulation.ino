#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC210_Pulse_duration_modulation
//

//  definition of variables

int   iTimeHigh;    // analog value for time high TH
int   iTimeLow;     // analog value for time low  TL

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

// Read analog values for time high and time low
iTimeHigh = analogRead ( CONTROLLINO_A6 );
iTimeLow  = analogRead ( CONTROLLINO_A7 );

if (digitalRead (CONTROLLINO_A0) )
{
  digitalWrite ( CONTROLLINO_D3, HIGH);
  delay ( iTimeHigh*4 );                  // *4 - gives a more visible result
  digitalWrite ( CONTROLLINO_D3, LOW);
  delay ( iTimeLow*4 );                   // *4 - gives a more visible result
}
} //loop
