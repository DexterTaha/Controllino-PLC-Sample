#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC204_Star_triangle_circuit
//

//  definition of variables

int   iStatus=0;    // 0-Stop, 1-Star, 2-Triangle

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A4, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);

}


//
//  Loop
//
void loop() {

// start motor in star circuit only if stopped
if ( (iStatus == 0) && digitalRead (CONTROLLINO_A0) )  {
  iStatus = 1;            // Status Motor 1-star
  digitalWrite(CONTROLLINO_D0, HIGH);  // contactor K1
  digitalWrite(CONTROLLINO_D1, HIGH);  // contactor K2
  }

// switch motor in triangle circuit only if currenly in star
if ( (iStatus == 1) && digitalRead (CONTROLLINO_A2) )  {
  iStatus = 2;            // Status Motor 2-triangle
  digitalWrite(CONTROLLINO_D1, LOW);   // contactor K2
  digitalWrite(CONTROLLINO_D2, HIGH);  // contactor K3
  }

// Motor stoppen, unabhängig vom vorhergehenden Motor Status
if ( digitalRead (CONTROLLINO_A4) )  {
  iStatus = 0;            // Status Motor 0-stopped
  digitalWrite(CONTROLLINO_D0, LOW);   // all contactor off
  digitalWrite(CONTROLLINO_D1, LOW);   // alle contactor off
  digitalWrite(CONTROLLINO_D2, LOW);   // alle contactor off
  delay (5000);           // wait untl motor is fully stopped
  }


} //loop
