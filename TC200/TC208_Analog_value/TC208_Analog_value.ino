#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC208_Analog_value
//

//  definition of variables

int   iValue;            // analog value
                         // 0 - 1024  equals to 0V - 24V
                         // Analog power on the Trainingsboard is 0V - 10V
                         // usable values
                         //   100% -> 320
                         //   and so on

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

// Read analog value
iValue = analogRead ( CONTROLLINO_A6 );

// iValue > 32
if ( (iValue > 32) )
    digitalWrite ( CONTROLLINO_D0, HIGH);
  else
    digitalWrite ( CONTROLLINO_D0, LOW);

// iValue > 64
if ( iValue > 64 )
    digitalWrite ( CONTROLLINO_D1, HIGH);
  else
    digitalWrite ( CONTROLLINO_D1, LOW);

// iValue > 96
if ( iValue > 96 )
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

// iValue > 128
if ( iValue > 128)
    digitalWrite ( CONTROLLINO_D3, HIGH);
  else
    digitalWrite ( CONTROLLINO_D3, LOW);

// iValue > 160
if ( iValue > 160 )
    digitalWrite ( CONTROLLINO_D4, HIGH);
  else
    digitalWrite ( CONTROLLINO_D4, LOW);

// iValue > 192
if ( iValue > 192 )
    digitalWrite ( CONTROLLINO_D5, HIGH);
  else
    digitalWrite ( CONTROLLINO_D5, LOW);

// iValue > 224
if ( iValue > 224 )
    digitalWrite ( CONTROLLINO_D6, HIGH);
  else
    digitalWrite ( CONTROLLINO_D6, LOW);

// iValue > 256
if ( iValue > 256 )
    digitalWrite ( CONTROLLINO_D7, HIGH);
  else
    digitalWrite ( CONTROLLINO_D7, LOW);

} //loop
