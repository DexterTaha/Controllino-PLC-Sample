#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC306_Automate_de_vides
//

// Définition des variables

bool bAllume;              // Automate ON/OFF

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
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

  // Allumer / Éteindre
  if (digitalRead(CONTROLLINO_A0))
  {
    bAllume = true;
  }
  else
  {
    bAllume = false;
  }

  // Démarrer le processus avec un capteur de barrière
  if (digitalRead(CONTROLLINO_A1) && bAllume)
  {
    // Démarrer la ligne d'assemblage 1
    // Attendre que le capteur de barrière 2 détecte une bouteille
    while (digitalRead(CONTROLLINO_A2) == LOW)
    {
      digitalWrite(CONTROLLINO_D0, HIGH);
    }
    // Arrêter la ligne d'assemblage 1
    digitalWrite(CONTROLLINO_D0, LOW);
    // Démarrer le scanner de codes-barres jusqu'à la lecture du code
    while (digitalRead(CONTROLLINO_A3) == LOW)
    {
      digitalWrite(CONTROLLINO_D1, HIGH);
    }
    // Arrêter le scanner de codes-barres
    digitalWrite(CONTROLLINO_D1, LOW);
    // Démarrer la ligne d'assemblage 2
    // Attendre que le capteur de barrière 3 détecte une bouteille
    while (digitalRead(CONTROLLINO_A5) == LOW)
    {
      digitalWrite(CONTROLLINO_D2, HIGH);
    }
    // Arrêter la ligne d'assemblage 2
    digitalWrite(CONTROLLINO_D2, LOW);
    // Démarrer la presse à bouteilles
    digitalWrite(CONTROLLINO_D3, HIGH);
    // Temps pour presser la bouteille
    delay(5000);
    // Arrêter la presse à bouteilles
    digitalWrite(CONTROLLINO_D3, LOW);
    // Démarrer la ligne d'assemblage 2
    // Attendre que le capteur de barrière 3 détecte une bouteille
    while (digitalRead(CONTROLLINO_A5) == HIGH)
    {
      digitalWrite(CONTROLLINO_D2, HIGH);
    }
    // Arrêter la ligne d'assemblage 2
    digitalWrite(CONTROLLINO_D2, LOW);
  }

}
