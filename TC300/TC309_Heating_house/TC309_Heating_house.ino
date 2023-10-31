#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC310_Controle_store

// Définition des variables

bool bOn;             // Mode automatique-vrai, mode manuel-faux
bool bCoupeThermique; // Commutateur de surchauffe
int iTempChaudiere;   // Température actuelle de la chaudière
int iTempPiece;       // Température actuelle de la pièce

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Lire les valeurs analogiques du capteur de température de la pièce et de la chaudière
  iTempPiece = analogRead(CONTROLLINO_A6);
  iTempChaudiere = analogRead(CONTROLLINO_A7);

  // Détecter la mise en marche/arrêt
  if (digitalRead(CONTROLLINO_A0))
    bOn = true;
  else
    bOn = false;

  // Réinitialiser la coupure thermique de la chaudière
  if (digitalRead(CONTROLLINO_A1))
  {
    bCoupeThermique = false;
  }

  // Détecter la coupure thermique de la chaudière
  if (!digitalRead(CONTROLLINO_A3))
  {
    bCoupeThermique = true;
  }

  // Activation/désactivation de la torche de chauffage
  if ((iTempChaudiere < 200) && !bCoupeThermique && bOn)
  {
    digitalWrite(CONTROLLINO_D1, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D1, LOW);
  }

  // Activation/désactivation de la pompe de chauffage de la pièce
  if ((iTempPiece < 100) && !bCoupeThermique && bOn)
  {
    digitalWrite(CONTROLLINO_D3, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D3, LOW);
  }

  // Signalisation du chauffage en marche
  if (bOn)
  {
    digitalWrite(CONTROLLINO_D0, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D0, LOW);
  }

  // Signalisation de l'ALARME
  if (bCoupeThermique)
  {
    digitalWrite(CONTROLLINO_D2, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D2, LOW);
  }
}
