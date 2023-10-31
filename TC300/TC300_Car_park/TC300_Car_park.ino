#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC300_Parking
//

// Définition des variables

int iCompteur;      // compter le nombre de voitures
bool bFlanc = LOW;  // rebondissement de la barrière lumineuse

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A7, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Barrière lumineuse d'entrée, compter la voiture
  if ((bFlanc == LOW) && (digitalRead(CONTROLLINO_A0) == HIGH)) {
    iCompteur++;
    bFlanc = HIGH; // compter seulement lorsque le flanc passe de Low -> High
  }

  // Réinitialiser le compteur à 0
  if ((bFlanc == LOW) && (digitalRead(CONTROLLINO_A1) == HIGH)) {
    iCompteur = 0;
    bFlanc = HIGH;
  }

  // Ajuster le compteur +1
  if ((bFlanc == LOW) && (digitalRead(CONTROLLINO_A2) == HIGH)) {
    iCompteur++;
    bFlanc = HIGH;
  }

  // Barrière lumineuse de sortie
  if ((bFlanc == LOW) && (digitalRead(CONTROLLINO_A7) == HIGH)) {
    iCompteur--;
    if (iCompteur < 0) iCompteur = 0;
    bFlanc = HIGH;
  }

  // Barrière lumineuse d'entrée
  if (iCompteur < 5) {
    digitalWrite(CONTROLLINO_D0, HIGH);
    digitalWrite(CONTROLLINO_D1, LOW);
  }

  // Barrière lumineuse d'entrée
  if (iCompteur >= 5) {
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D1, HIGH);
  }

  // Réinitialiser la variable bFlanc uniquement lorsque le flanc passe de High -> Low
  if (!(digitalRead(CONTROLLINO_A0)) && !(digitalRead(CONTROLLINO_A1)) && !(digitalRead(CONTROLLINO_A2)) && !(digitalRead(CONTROLLINO_A7))) {
    bFlanc = LOW;
    delay(20); //
  }
}
