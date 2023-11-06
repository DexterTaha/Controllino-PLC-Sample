#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC205_Surveillance_de_niveau
//

// Définition des variables
bool bRemplissage = false; // true - En marche, false - Arrêt

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_A7, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Bouton poussoir marche
  if (digitalRead(CONTROLLINO_A0) == HIGH)
    bRemplissage = true;

  // Bouton poussoir arrêt
  if (digitalRead(CONTROLLINO_A1) == LOW)
    bRemplissage = false;

  // Démarrer la Pompe1 jusqu'à 100%
  if (bRemplissage && digitalRead(CONTROLLINO_A7) == LOW) {
    digitalWrite(CONTROLLINO_D0, HIGH);
  } else {
    digitalWrite(CONTROLLINO_D0, LOW);
    bRemplissage = false;
  }

  // Démarrer la Pompe2 jusqu'à 80%
  if (bRemplissage && digitalRead(CONTROLLINO_A6) == LOW) {
    digitalWrite(CONTROLLINO_D1, HIGH);
  } else {
    digitalWrite(CONTROLLINO_D1, LOW);
  }

  // Signal <10%
  if (digitalRead(CONTROLLINO_A5) == LOW) {
    digitalWrite(CONTROLLINO_D3, HIGH);
  } else {
    digitalWrite(CONTROLLINO_D3, LOW);
  }
}
