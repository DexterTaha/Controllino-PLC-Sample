#include <SPI.h>
#include <Controllino.h>

//
//  Tâche : TC101_NAND_NOR_XOR
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
  pinMode(CONTROLLINO_A5, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
}

//
//  Boucle
//
void loop() {
  // Portes logiques NAND, NOR et XOR

  // NAND
  // 0 0    1
  // 0 1    1
  // 1 0    1
  // 1 1    0
  if (digitalRead(CONTROLLINO_A0) && digitalRead(CONTROLLINO_A1))
    digitalWrite(CONTROLLINO_D0, LOW);
  else
    digitalWrite(CONTROLLINO_D0, HIGH);

  // NOR
  // 0 0    1
  // 0 1    0
  // 1 0    0
  // 1 1    0
  if (!digitalRead(CONTROLLINO_A3) && !digitalRead(CONTROLLINO_A4))
    digitalWrite(CONTROLLINO_D1, HIGH);
  else
    digitalWrite(CONTROLLINO_D1, LOW);

  // XOR
  // 0 0    0
  // 0 1    1
  // 1 0    1
  // 1 1    0
  if ((digitalRead(CONTROLLINO_A5) && !digitalRead(CONTROLLINO_A6)) || (!digitalRead(CONTROLLINO_A5) && digitalRead(CONTROLLINO_A6)))
    digitalWrite(CONTROLLINO_D2, HIGH);
  else
    digitalWrite(CONTROLLINO_D2, LOW);
}
