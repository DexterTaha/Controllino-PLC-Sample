#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC304_Ligne_d'assemblage
//

// Définition des variables

bool bAllume;         // true-allumé, false-éteint
bool bMouvementGauche;  // aller vers la gauche
bool bMouvementDroite;   // aller vers la droite
bool bUrgence;          // true-urgence, false-éteint

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Allumer / Éteindre
  if (digitalRead(CONTROLLINO_A0))
    bAllume = true;
  else
    bAllume = false;

  // Détecter le mouvement vers la gauche
  if (digitalRead(CONTROLLINO_A2))
  {
    bMouvementGauche = true;
    bMouvementDroite = false;
  }

  // Détecter le mouvement vers la droite
  if (digitalRead(CONTROLLINO_A6))
  {
    bMouvementDroite = true;
    bMouvementGauche = false;
  }

  // Réinitialiser l'urgence
  if (digitalRead(CONTROLLINO_A4))
  {
    bUrgence = false;
    bMouvementDroite = false;
    bMouvementGauche = false;
  }

  // Détecter l'urgence ou une défaillance de mouvement dans les deux sens en même temps
  if (!digitalRead(CONTROLLINO_A3) || (bMouvementGauche && bMouvementDroite))
  {
    bUrgence = true;
  }

  // Sélectionner la direction du moteur
  if (bMouvementGauche && !bUrgence && bAllume)
  {
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D1, HIGH);
  }
  else
  {
    if (bMouvementDroite && !bUrgence && bAllume)
    {
      digitalWrite(CONTROLLINO_D1, LOW);
      digitalWrite(CONTROLLINO_D0, HIGH);
    }
    else
    {
      digitalWrite(CONTROLLINO_D1, LOW);
      digitalWrite(CONTROLLINO_D0, LOW);
    }
  }

  // Signaler l'urgence
  if (bUrgence)
  {
    digitalWrite(CONTROLLINO_D2, HIGH);
  }
  else
    digitalWrite(CONTROLLINO_D2, LOW);

} 
