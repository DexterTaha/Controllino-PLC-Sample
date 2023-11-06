#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC104_Générateur_d'impulsions
//

// Définition des variables
int iDelai = 200;

//
// Configuration
//
void setup() {
  // Définir la broche en tant qu'entrée
  pinMode(CONTROLLINO_A0, INPUT);
  // Définir la broche en tant que sortie
  pinMode(CONTROLLINO_D0, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Générateur d'impulsions

  if (digitalRead(CONTROLLINO_A0)) {
    digitalWrite(CONTROLLINO_D0, HIGH);
    delay(iDelai);
    digitalWrite(CONTROLLINO_D0, LOW);
    delay(iDelai);
  }
}
