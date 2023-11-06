#include <SPI.h>
#include <Controllino.h>

// Tâche : TC309_Chauffage_Maison

// Définition des variables

bool isChauffageAllume = false; // Chauffage allumé - vrai, Chauffage éteint - faux
int tempBouilloire = 0;         // Température actuelle de la bouilloire
int tempPiece = 0;              // Température actuelle de la pièce

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_A7, INPUT);
  
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Lire les valeurs analogiques du capteur de température de la pièce et de la température de la bouilloire
  tempPiece = analogRead(CONTROLLINO_A6);
  tempBouilloire = analogRead(CONTROLLINO_A7);

  // Détecter l'état du chauffage central
  if (digitalRead(CONTROLLINO_A0))
  {
    isChauffageAllume = true;
    digitalWrite(CONTROLLINO_D0, HIGH);
  }
  else
  {
    isChauffageAllume = false;
    digitalWrite(CONTROLLINO_D0, LOW);
  }

  // Contrôle de la charge de la bouilloire
  if (isChauffageAllume) {
    if (tempBouilloire < 60) {
      digitalWrite(CONTROLLINO_D1, HIGH); // Allumer le brûleur
    } else if (tempBouilloire >= 80 || !digitalRead(CONTROLLINO_A3)) {
      digitalWrite(CONTROLLINO_D1, LOW); // Éteindre le brûleur
      digitalWrite(CONTROLLINO_D2, HIGH); // Générer une alarme
    } else {
      digitalWrite(CONTROLLINO_D1, LOW); // Éteindre le brûleur
      digitalWrite(CONTROLLINO_D2, LOW); // Éteindre l'alarme
    }
  } else {
    digitalWrite(CONTROLLINO_D1, LOW); // Éteindre le brûleur
    digitalWrite(CONTROLLINO_D2, LOW); // Éteindre l'alarme
  }

  // Contrôle du chauffage de la pièce
  if (tempPiece < 20 && isChauffageAllume) {
    digitalWrite(CONTROLLINO_D3, HIGH); // Allumer la pompe de circulation
  } else {
    digitalWrite(CONTROLLINO_D3, LOW); // Éteindre la pompe de circulation
  }
}
