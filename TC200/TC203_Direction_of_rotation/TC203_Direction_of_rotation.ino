#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC203_Direction_of_rotation
//

//  definition of variables

int   iDirection=0;    // direction of rotation 0-stop, 1-right, 2-left

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A4, INPUT);

pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);

}

//
//  Loop
//
void loop() {

// start motor only if currently stopped, direction left
if ( ( iDirection == 0 ) && digitalRead (CONTROLLINO_A1) )  {
  digitalWrite(CONTROLLINO_D1, HIGH);
  iDirection = 1;
}

// start motor only if currently stopped, direction right
if ( ( iDirection == 0 ) && digitalRead (CONTROLLINO_A2) )  {
  digitalWrite(CONTROLLINO_D2, HIGH);
  iDirection = 2;
}

// stop motor from any direction
if ( digitalRead (CONTROLLINO_A4) )  {
  digitalWrite(CONTROLLINO_D1, LOW);
  digitalWrite(CONTROLLINO_D2, LOW);
  delay (5000);     // Wait until Motor is fully stopped
  iDirection = 0;
}

} //loop
