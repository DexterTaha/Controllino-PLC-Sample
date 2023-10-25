#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC206_Level_Monitoring_2
//

//  definition of variables

int   iValue;            // Value fill level
                         // 0 - 1024  equals to 0V - 24V
                         // Analog value on the Trainingsboard is 0V - 10V
                         // usable values
                         //   100% -> 320
                         //    80% -> 260
                         //    10% -> 32
bool  bOverrun;          // false-under level, true-overrun
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

// Read fuel level from analog Sensor
iValue = analogRead ( CONTROLLINO_A7 );

// Check for overrun
if ( digitalRead ( CONTROLLINO_A5 ) == HIGH )
    {
      bOverrun = true;
      bFilling=false;
    }
  else
    bOverrun = false;

// push button start filling
if ( digitalRead ( CONTROLLINO_A0 ) == HIGH )
    bFilling = true;

// push button stop filling
if ( digitalRead ( CONTROLLINO_A1 ) == LOW )
    bFilling = false;

// start/stop pump1 and or pump2
if ( bFilling && !bOverrun )
  {
    if ( iValue > 320 )    // value above 1000 - stopp both pumps
    {
      digitalWrite ( CONTROLLINO_D0, LOW);
      digitalWrite ( CONTROLLINO_D1, LOW);
      bFilling=false;
    }
    else
    {
      if ( iValue < 260 )    // value below 800 - start both pumps
        {
          digitalWrite ( CONTROLLINO_D0, HIGH);
          digitalWrite ( CONTROLLINO_D1, HIGH);
        }
        else // value between 800 and 1000 - keep pump1 running
        {
          digitalWrite ( CONTROLLINO_D0, HIGH);
          digitalWrite ( CONTROLLINO_D1, LOW);
        }
    }
  }
  else  // on overrun, stop both pumps
  {
    digitalWrite ( CONTROLLINO_D0, LOW);
    digitalWrite ( CONTROLLINO_D1, LOW);
    bFilling=false;
  }
  
// Signaling ALARM
if ( bOverrun )
    digitalWrite ( CONTROLLINO_D2, HIGH);
  else
    digitalWrite ( CONTROLLINO_D2, LOW);

// Signaling <10%
if ( iValue < 32 )
    digitalWrite ( CONTROLLINO_D3, HIGH);
  else
    digitalWrite ( CONTROLLINO_D3, LOW);


} //loop
