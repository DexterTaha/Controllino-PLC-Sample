#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC201_Lumière_du_couloir
//

// Définition des variables
const long iDureeEclairage = 5000;         // Durée d'éclairage des lumières normales
const long iDureeEclairageVeille = 2000;    // Durée d'éclairage de la lumière de veille
int iLumiere = LOW;                         // Lumières normales allumées
int iLumiereVeille = LOW;                   // Lumière de veille allumée
unsigned long tempsPrecedent = 0;           // Millisecondes précédentes stockées
unsigned long tempsActuel;                  // Millisecondes actuelles

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
  pinMode(CONTROLLINO_D4, OUTPUT);
  pinMode(CONTROLLINO_D5, OUTPUT);
  pinMode(CONTROLLINO_D6, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Connexion_logique

  tempsActuel = millis();

  // Éteindre la lumière après iDureeEclairage
  if ((tempsActuel - tempsPrecedent >= iDureeEclairage) && (iLumiere == HIGH)) {
    iLumiere = LOW;
    iLumiereVeille = HIGH;
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D1, LOW);
    digitalWrite(CONTROLLINO_D2, LOW);
    digitalWrite(CONTROLLINO_D3, LOW);
    digitalWrite(CONTROLLINO_D4, LOW);
    digitalWrite(CONTROLLINO_D5, LOW);
    digitalWrite(CONTROLLINO_D6, LOW);
  }

  // Éteindre la lumière après iDureeEclairageVeille
  if ((tempsActuel - tempsPrecedent >= iDureeEclairage + iDureeEclairageVeille) && (iLumiereVeille == HIGH)) {
    iLumiereVeille = LOW;
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D1, LOW);
    digitalWrite(CONTROLLINO_D2, LOW);
    digitalWrite(CONTROLLINO_D3, LOW);
    digitalWrite(CONTROLLINO_D4, LOW);
    digitalWrite(CONTROLLINO_D5, LOW);
    digitalWrite(CONTROLLINO_D6, LOW);
  }

  // Allumer les lumières
  if (digitalRead(CONTROLLINO_A0) || digitalRead(CONTROLLINO_A2) || digitalRead(CONTROLLINO_A4) || digitalRead(CONTROLLINO_A6)) {
    iLumiere = HIGH;
    iLumiereVeille = LOW;
    digitalWrite(CONTROLLINO_D0, HIGH);
    digitalWrite(CONTROLLINO_D1, HIGH);
    digitalWrite(CONTROLLINO_D2, HIGH);
    digitalWrite(CONTROLLINO_D3, HIGH);
    digitalWrite(CONTROLLINO_D4, HIGH);
    digitalWrite(CONTROLLINO_D5, HIGH);
    digitalWrite(CONTROLLINO_D6, HIGH);
    tempsPrecedent = tempsActuel;
  }
}
