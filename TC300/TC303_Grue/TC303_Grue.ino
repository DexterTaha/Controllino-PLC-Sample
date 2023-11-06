#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC303_Grue
//

// Définition des variables

bool bAllume;        // true-allumé, false-éteint
bool bMonterCharge;  // monter la charge
bool bDescendreCharge;  // décharger
bool bEnHaut;        // en haut atteint
bool bUrgence;       // urgence-true
bool bChargeTropHaute;  // la charge est trop haute
int iChargeGrue;     // valeur de charge analogique sur le treuil

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Lire la valeur de charge analogique sur le treuil
  iChargeGrue = analogRead(CONTROLLINO_A7);

  // Allumer / Éteindre
  if (digitalRead(CONTROLLINO_A0))
    bAllume = true;
  else
    bAllume = false;

  // Détecter la grue en haut
  if (digitalRead(CONTROLLINO_A3))
  {
    bEnHaut = true;
  }
  else
  {
    bEnHaut = false;
  }

  // Détecter la montée
  if (digitalRead(CONTROLLINO_A1) && !bEnHaut)
  {
    bMonterCharge = true;
  }
  else
  {
    bMonterCharge = false;
  }

  // Détecter la descente
  if (digitalRead(CONTROLLINO_A2))
  {
    bDescendreCharge = true;
  }
  else
  {
    bDescendreCharge = false;
  }

  // Réinitialiser l'urgence
  if (digitalRead(CONTROLLINO_A4) || (iChargeGrue > 600))
  {
    bUrgence = false;
  }

  // Détecter l'urgence
  if (!digitalRead(CONTROLLINO_A5))
  {
    bUrgence = true;
  }

  // Détecter une charge élevée
  if (iChargeGrue > 200)
  {
    bChargeTropHaute = true;
  }
  else
  {
    bChargeTropHaute = false;
  }

  if (bMonterCharge && !bUrgence && !bChargeTropHaute && bAllume)
  {
    digitalWrite(CONTROLLINO_D1, LOW);
    digitalWrite(CONTROLLINO_D0, HIGH);
  }
  else
  {
    if (bDescendreCharge && !bUrgence && bAllume)
    {
      digitalWrite(CONTROLLINO_D0, LOW);
      digitalWrite(CONTROLLINO_D1, HIGH);
    }
    else
    {
      digitalWrite(CONTROLLINO_D0, LOW);
      digitalWrite(CONTROLLINO_D1, LOW);
    }
  }

  // Signaler que la grue est allumée
  if (bAllume)
    digitalWrite(CONTROLLINO_D3, HIGH);
  else
    digitalWrite(CONTROLLINO_D3, LOW);

  // Signaler l'urgence
  if (bUrgence || bChargeTropHaute)
    digitalWrite(CONTROLLINO_D2, HIGH);
  else
    digitalWrite(CONTROLLINO_D2, LOW);
}
