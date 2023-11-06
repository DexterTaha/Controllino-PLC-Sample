#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC203_Sens_de_rotation
//

// Définition des variables
int iDirection = 0; // sens de rotation 0 - arrêt, 1 - droite, 2 - gauche

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Démarrer le moteur uniquement s'il est actuellement arrêté, direction gauche
  if (iDirection == 0 && digitalRead(CONTROLLINO_A1)) {
    digitalWrite(CONTROLLINO_D1, HIGH);
    iDirection = 1;
  }

  // Démarrer le moteur uniquement s'il est actuellement arrêté, direction droite
  if (iDirection == 0 && digitalRead(CONTROLLINO_A2)) {
    digitalWrite(CONTROLLINO_D2, HIGH);
    iDirection = 2;
  }

  // Arrêter le moteur à partir de n'importe quelle direction
  if (digitalRead(CONTROLLINO_A4)) {
    digitalWrite(CONTROLLINO_D1, LOW);
    digitalWrite(CONTROLLINO_D2, LOW);
    delay(5000); // Attendre que le moteur s'arrête complètement
    iDirection = 0;
  }
}
