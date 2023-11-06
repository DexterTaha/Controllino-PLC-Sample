#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC209_Compteur_Rapide
//

// Définition des variables

int   iCompteur;                  // Compter les impulsions par seconde
int   iDernierCompteur = 3;       // Compter depuis la dernière seconde
unsigned long tempsPrecedent = 0;  // Millisecondes précédentes stockées
unsigned long tempsActuel;         // Millisecondes actuelles


//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
  pinMode(CONTROLLINO_D4, OUTPUT);
  pinMode(CONTROLLINO_D5, OUTPUT);
  pinMode(CONTROLLINO_D6, OUTPUT);
  pinMode(CONTROLLINO_D7, OUTPUT);

  // Gestionnaire d'interruption
  pinMode(CONTROLLINO_IN0, INPUT);
  attachInterrupt(digitalPinToInterrupt(CONTROLLINO_IN0), compter, RISING);
  // LOW pour déclencher l'interruption chaque fois que la broche est basse,
  // CHANGE pour déclencher l'interruption chaque fois que la broche change de valeur
  // RISING pour déclencher lorsque la broche passe de basse à haute,
  // FALLING pour déclencher lorsque la broche passe de haute à basse.

}


//
// Boucle
//
void loop() {

  // Temps actuel
  tempsActuel = millis();

  // attribuer iDernierCompteur = iCompteur
  if (tempsActuel - tempsPrecedent >= 1000)
  {
    // Chaque changement de front déclenche une interruption,
    // donc chaque impulsion est comptée deux fois
    iDernierCompteur = iCompteur;
    iCompteur = 0;
    tempsPrecedent = tempsActuel;
  }

  // iDernierCompteur > 100
  if (iDernierCompteur >= 100)
    digitalWrite(CONTROLLINO_D0, HIGH);
  else
    digitalWrite(CONTROLLINO_D0, LOW);

  // iDernierCompteur > 200
  if (iDernierCompteur > 200)
    digitalWrite(CONTROLLINO_D1, HIGH);
  else
    digitalWrite(CONTROLLINO_D1, LOW);

  // iDernierCompteur > 300
  if (iDernierCompteur > 300)
    digitalWrite(CONTROLLINO_D2, HIGH);
  else
    digitalWrite(CONTROLLINO_D2, LOW);

  // iDernierCompteur > 400
  if (iDernierCompteur > 400)
    digitalWrite(CONTROLLINO_D3, HIGH);
  else
    digitalWrite(CONTROLLINO_D3, LOW);

  // iDernierCompteur > 500
  if (iDernierCompteur > 500)
    digitalWrite(CONTROLLINO_D4, HIGH);
  else
    digitalWrite(CONTROLLINO_D4, LOW);

  // iDernierCompteur > 600
  if (iDernierCompteur > 600)
    digitalWrite(CONTROLLINO_D5, HIGH);
  else
    digitalWrite(CONTROLLINO_D5, LOW);

  // iDernierCompteur > 700
  if (iDernierCompteur > 700)
    digitalWrite(CONTROLLINO_D6, HIGH);
  else
    digitalWrite(CONTROLLINO_D6, LOW);

  // iDernierCompteur > 800
  if (iDernierCompteur > 800)
    digitalWrite(CONTROLLINO_D7, HIGH);
  else
    digitalWrite(CONTROLLINO_D7, LOW);

} //loop

void compter() {
  iCompteur++;
}
