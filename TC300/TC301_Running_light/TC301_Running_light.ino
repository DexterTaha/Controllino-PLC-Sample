#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC301_Lumière_clignotante
//

// Définition des variables

int iCompteur = 0;  // compteur de 0 à 7
bool bAllume;      // true-Allumé, false-Éteint
bool bDirection;   // false-droite, true-gauche

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
  pinMode(CONTROLLINO_D4, OUTPUT);
  pinMode(CONTROLLINO_D5, OUTPUT);
  pinMode(CONTROLLINO_D6, OUTPUT);
  pinMode(CONTROLLINO_D7, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Vérifier si le compteur dépasse 7
  if (iCompteur == 8)
    iCompteur = 0;

  // Vérifier si le compteur est inférieur à 0
  if (iCompteur == -1)
    iCompteur = 7;

  // Compteur allumé/éteint
  if (digitalRead(CONTROLLINO_A0) == HIGH)
    bAllume = true;
  else
    bAllume = false;

  // Direction du compteur
  if (digitalRead(CONTROLLINO_A1) == HIGH)
    bDirection = true;
  else
    bDirection = false;

  // iCompteur = 0
  if (bAllume && (iCompteur == 0))
    digitalWrite(CONTROLLINO_D0, HIGH);
  else
    digitalWrite(CONTROLLINO_D0, LOW);

  // iCompteur = 1
  if (bAllume && (iCompteur == 1))
    digitalWrite(CONTROLLINO_D1, HIGH);
  else
    digitalWrite(CONTROLLINO_D1, LOW);

  // iCompteur = 2
  if (bAllume && (iCompteur == 2))
    digitalWrite(CONTROLLINO_D2, HIGH);
  else
    digitalWrite(CONTROLLINO_D2, LOW);

  // iCompteur = 3
  if (bAllume && (iCompteur == 3))
    digitalWrite(CONTROLLINO_D3, HIGH);
  else
    digitalWrite(CONTROLLINO_D3, LOW);

  // iCompteur = 4
  if (bAllume && (iCompteur == 4))
    digitalWrite(CONTROLLINO_D4, HIGH);
  else
    digitalWrite(CONTROLLINO_D4, LOW);

  // iCompteur = 5
  if (bAllume && (iCompteur == 5))
    digitalWrite(CONTROLLINO_D5, HIGH);
  else
    digitalWrite(CONTROLLINO_D5, LOW);

  // iCompteur = 6
  if (bAllume && (iCompteur == 6))
    digitalWrite(CONTROLLINO_D6, HIGH);
  else
    digitalWrite(CONTROLLINO_D6, LOW);

  // iCompteur = 7
  if (bAllume && (iCompteur == 7))
    digitalWrite(CONTROLLINO_D7, HIGH);
  else
    digitalWrite(CONTROLLINO_D7, LOW);

  delay(500);

  // Définir la nouvelle valeur de iCompteur
  if (bDirection == false)
    iCompteur++;
  else
    iCompteur--;

}
