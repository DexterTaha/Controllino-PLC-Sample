#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC302_Compteur
//

// Définition des variables

int iCompteur = 0;  // compteur de 0 à 7
bool bAllume;      // true-Allumé, false-Éteint
bool bFlanc = LOW;  // debounce pour la barrière de lumière

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);

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
    iCompteur = 7;

  // Vérifier si le compteur est inférieur à 0
  if (iCompteur == -1)
    iCompteur = 0;

  // iCompteur = 0
  if (iCompteur == 0)
    digitalWrite(CONTROLLINO_D0, HIGH);
  else
    digitalWrite(CONTROLLINO_D0, LOW);

  // iCompteur = 1
  if (iCompteur == 1)
    digitalWrite(CONTROLLINO_D1, HIGH);
  else
    digitalWrite(CONTROLLINO_D1, LOW);

  // iCompteur = 2
  if (iCompteur == 2)
    digitalWrite(CONTROLLINO_D2, HIGH);
  else
    digitalWrite(CONTROLLINO_D2, LOW);

  // iCompteur = 3
  if (iCompteur == 3)
    digitalWrite(CONTROLLINO_D3, HIGH);
  else
    digitalWrite(CONTROLLINO_D3, LOW);

  // iCompteur = 4
  if (iCompteur == 4)
    digitalWrite(CONTROLLINO_D4, HIGH);
  else
    digitalWrite(CONTROLLINO_D4, LOW);

  // iCompteur = 5
  if (iCompteur == 5)
    digitalWrite(CONTROLLINO_D5, HIGH);
  else
    digitalWrite(CONTROLLINO_D5, LOW);

  // iCompteur = 6
  if (iCompteur == 6)
    digitalWrite(CONTROLLINO_D6, HIGH);
  else
    digitalWrite(CONTROLLINO_D6, LOW);

  // iCompteur = 7
  if (iCompteur == 7)
    digitalWrite(CONTROLLINO_D7, HIGH);
  else
    digitalWrite(CONTROLLINO_D7, LOW);

  // Ajuster le compteur +1
  if (bFlanc == LOW && digitalRead(CONTROLLINO_A0) == HIGH)
  {
    iCompteur++;
    bFlanc = true;
  }

  // Ajuster le compteur -1
  if (bFlanc == LOW && digitalRead(CONTROLLINO_A1) == HIGH)
  {
    iCompteur--;
    bFlanc = true;
  }

  // Définir le compteur à 0
  if (bFlanc == LOW && digitalRead(CONTROLLINO_A2) == HIGH)
  {
    iCompteur = 0;
    bFlanc = true;
  }

  // Réinitialiser bFlanc lors du changement de flanc de High à Low
  if (!digitalRead(CONTROLLINO_A0) && !digitalRead(CONTROLLINO_A1) && !digitalRead(CONTROLLINO_A2))
  {
    bFlanc = false;
    delay(20); // Débordement
  }
}
