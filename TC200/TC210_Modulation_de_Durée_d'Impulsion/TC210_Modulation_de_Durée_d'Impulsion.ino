#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC210_Modulation_de_Durée_d'Impulsion
//

// Définition des variables

int iDureeHaute;  // Valeur analogique pour la durée haute TH
int iDureeBasse;  // Valeur analogique pour la durée basse TL

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
  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_A7, INPUT);

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

  // Lire les valeurs analogiques pour la durée haute et la durée basse
  iDureeHaute = analogRead(CONTROLLINO_A6);
  iDureeBasse = analogRead(CONTROLLINO_A7);

  if (digitalRead(CONTROLLINO_A0))
  {
    digitalWrite(CONTROLLINO_D3, HIGH);
    delay(iDureeHaute * 4);  // * 4 - donne un résultat plus visible
    digitalWrite(CONTROLLINO_D3, LOW);
    delay(iDureeBasse * 4);  // * 4 - donne un résultat plus visible
  }
}
