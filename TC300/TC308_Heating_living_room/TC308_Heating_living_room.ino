#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC308_Chauffage_salon

// Définition des variables

int iTempActuelle;  // Température actuelle de la pièce
int iTempSouhaitee; // Température souhaitée de la pièce

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_A7, INPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Lire les valeurs analogiques du capteur de température de la pièce et de la température souhaitée
  iTempActuelle = analogRead(CONTROLLINO_A6);
  iTempSouhaitee = analogRead(CONTROLLINO_A7);

  // Pompe de chauffage de la pièce on/off
  if (iTempActuelle < iTempSouhaitee)
  {
    digitalWrite(CONTROLLINO_D3, HIGH);
  }
  else
  {
    digitalWrite(CONTROLLINO_D3, LOW);
  }

}
