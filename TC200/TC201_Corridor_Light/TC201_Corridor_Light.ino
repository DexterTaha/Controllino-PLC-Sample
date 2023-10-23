#include <SPI.h>
#include <Controllino.h>

//
//  Task: TC201_Corridor_Light
//

//  definition of variables

const long iLightningTime = 5000;           // Lightning time of the normal lights
const long iLightningTimeStandby = 2000;    // Lightning time of the standby light
int iLight = LOW;                           // normal lights ON
int iLightStandby = LOW;                    // standby light ON
unsigned long previousMillis = 0;           // stored milliseconds
unsigned long currentMillis;                // actual milliseconds

//
//  Setup
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A4, INPUT);
pinMode(CONTROLLINO_A6, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);
pinMode(CONTROLLINO_D4, OUTPUT);
pinMode(CONTROLLINO_D5, OUTPUT);
pinMode(CONTROLLINO_D6, OUTPUT);

}


//
//  Loop
//
void loop() {

// Logical_connection

currentMillis = millis();

// switch off light after iLightningTime  
if ((currentMillis - previousMillis >= iLightningTime) && (iLight == HIGH)) {
    iLight = LOW;
    iLightStandby = HIGH;
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D2, LOW);
    digitalWrite(CONTROLLINO_D3, LOW);
    digitalWrite(CONTROLLINO_D4, LOW);
    digitalWrite(CONTROLLINO_D6, LOW);
}

// switch off light after iLightningTimeStandby  
if ((currentMillis - previousMillis >= iLightningTime + iLightningTimeStandby) && (iLightStandby == HIGH)) {
    iLightStandby = LOW;
    digitalWrite(CONTROLLINO_D1, LOW);
    digitalWrite(CONTROLLINO_D5, LOW);
}

// switch on lights 
if ( digitalRead (CONTROLLINO_A0) || digitalRead (CONTROLLINO_A2) || digitalRead (CONTROLLINO_A4) || digitalRead (CONTROLLINO_A6)) {
    iLight = HIGH;
    iLightStandby = LOW;
    digitalWrite(CONTROLLINO_D0, HIGH);
    digitalWrite(CONTROLLINO_D1, HIGH);
    digitalWrite(CONTROLLINO_D2, HIGH);
    digitalWrite(CONTROLLINO_D3, HIGH);
    digitalWrite(CONTROLLINO_D4, HIGH);
    digitalWrite(CONTROLLINO_D5, HIGH);
    digitalWrite(CONTROLLINO_D6, HIGH);
    previousMillis = currentMillis;
  }

} //loop
