#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC300_Car_park
//

//  definition of variables

int   iCounter;       // count number of cars
bool  bFlank=LOW;     // debounce light barrier 


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

// Light barrier entrance, count car
if ( (bFlank == LOW )  && (digitalRead (CONTROLLINO_A0) == HIGH ) )  {
  iCounter++;
  bFlank = HIGH;         // count only while flak switchs from Low -> High
}

// Reset counter to 0
if ( (bFlank == LOW )  && (digitalRead (CONTROLLINO_A1) == HIGH ) )  {
  iCounter = 0;
  bFlank = HIGH;
}

// adjust counter +1
if ( (bFlank == LOW )  && (digitalRead (CONTROLLINO_A2) == HIGH ) )  {
  iCounter++;
  bFlank = HIGH;
}

// Light barrier exit
if ( (bFlank == LOW )  && (digitalRead (CONTROLLINO_A7) == HIGH ) )  {
  iCounter--;
  if ( iCounter < 0 ) iCounter = 0;
  bFlank = HIGH;
}

// Light barrier entrance
if ( iCounter < 5  ) {
  digitalWrite(CONTROLLINO_D0, HIGH);
  digitalWrite(CONTROLLINO_D1, LOW);
    }

// Light barrier entrance
if ( iCounter >= 5  ) {
  digitalWrite(CONTROLLINO_D0, LOW);
  digitalWrite(CONTROLLINO_D1, HIGH);
    }


// reset variable iFlanke only while flank switches from High -> Low
if ( !(digitalRead (CONTROLLINO_A0)) && !(digitalRead (CONTROLLINO_A1)) && !(digitalRead (CONTROLLINO_A2)) && !(digitalRead (CONTROLLINO_A7)) )  {
  bFlank = LOW;
  delay (20);     //
  }

 
} //loop
