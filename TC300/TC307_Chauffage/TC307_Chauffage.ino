#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC307_Chauffage

// Définition des variables

bool bAllume;          // Mode automatique - vrai, mode manuel - faux
bool bCoupureThermique; // Passer en mode surchauffe de la chaudière
int iTempChaudiere;    // Capteur analogique de température de la chaudière

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Lire les valeurs analogiques du capteur de température de la chaudière
  iTempChaudiere = analogRead(CONTROLLINO_A7);

  // Détecter l'allumage / l'extinction
  if (digitalRead(CONTROLLINO_A0))
  {
    bAllume = true;
  }
  else
  {
    bAllume = false;
  }

  // Détecter la réinitialisation du coupe-circuit thermique de la chaudière
  if (digitalRead(CONTROLLINO_A4))
  {
    bCoupureThermique = false;
  }

  // Détecter la coupure thermique de la chaudière
  if (!digitalRead(CONTROLLINO_A3))
  {
    bCoupureThermique = true;
  }

  // Chauffage on/off
  if ((iTempChaudiere < 200) && !bCoupureThermique && bAllume)
  {
    digitalWrite(CONTROLLINO_D1, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D1, LOW);
  }

  // Signalisation du chauffage allumé
  if (bAllume)
  {
    digitalWrite(CONTROLLINO_D0, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D0, LOW);
  }

  // Signalisation de l'ALARME
  if (bCoupureThermique)
  {
    digitalWrite(CONTROLLINO_D2, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D2, LOW);
  }

}
