#include <Controllino.h>
#include <SPI.h>

//
// Tâche : TC103_Interrupteur_marche_arret_retard
//

// Définition des variables
int iDelai = 1000;

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Interrupteur_marche_retard

  if (digitalRead(CONTROLLINO_A0)) {
    delay(iDelai);
    digitalWrite(CONTROLLINO_D0, HIGH);
  } else {
    digitalWrite(CONTROLLINO_D0, LOW);
  }

  // Interrupteur_arret_retard

  if (digitalRead(CONTROLLINO_A3)) {
    digitalWrite(CONTROLLINO_D1, HIGH);
  } else {
    delay(iDelai);
    digitalWrite(CONTROLLINO_D1, LOW);
  }

  // Interrupteur_arret_retard_avec_delai

  if (digitalRead(CONTROLLINO_A5)) {
    delay(iDelai);
    digitalWrite(CONTROLLINO_D2, HIGH);
  } else {
    delay(iDelai);
    digitalWrite(CONTROLLINO_D2, LOW);
  }
}
