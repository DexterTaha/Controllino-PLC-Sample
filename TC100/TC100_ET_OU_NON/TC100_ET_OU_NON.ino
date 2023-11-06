#include <SPI.h>
#include <Controllino.h>

//
//  Tâche : TC100_ET_OU_NON
//

//
//  Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
//  Boucle
//
void loop() {
  // Portes logiques AND, OR et NOT

  // AND
  // 0 0    0
  // 0 1    0
  // 1 0    0
  // 1 1    1
  if (digitalRead(CONTROLLINO_A0) && digitalRead(CONTROLLINO_A1))
    digitalWrite(CONTROLLINO_D0, HIGH);
  else
    digitalWrite(CONTROLLINO_D0, LOW);

  // OR
  // 0 0    0
  // 0 1    1
  // 1 0    1
  // 1 1    1
  if (digitalRead(CONTROLLINO_A3) || digitalRead(CONTROLLINO_A4))
    digitalWrite(CONTROLLINO_D1, HIGH);
  else
    digitalWrite(CONTROLLINO_D1, LOW);

  // NOT
  // 0    1
  // 1    0
  if (digitalRead(CONTROLLINO_A6) == HIGH)
    digitalWrite(CONTROLLINO_D2, LOW);
  else
    digitalWrite(CONTROLLINO_D2, HIGH);
}
