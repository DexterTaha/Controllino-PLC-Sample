#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC204_Circuit_étoile_triangle
//

// Définition des variables
int iStatut = 0; // 0 - Arrêt, 1 - Étoile, 2 - Triangle

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Démarrer le moteur en circuit étoile uniquement s'il est actuellement arrêté
  if (iStatut == 0 && digitalRead(CONTROLLINO_A0)) {
    iStatut = 1; // Statut Moteur 1 - étoile
    digitalWrite(CONTROLLINO_D0, HIGH); // contacteur K1
    digitalWrite(CONTROLLINO_D1, HIGH); // contacteur K2
  }

  // Passer le moteur en circuit triangle uniquement s'il est actuellement en étoile
  if (iStatut == 1 && digitalRead(CONTROLLINO_A2)) {
    iStatut = 2; // Statut Moteur 2 - triangle
    digitalWrite(CONTROLLINO_D1, LOW); // contacteur K2
    digitalWrite(CONTROLLINO_D2, HIGH); // contacteur K3
  }

  // Arrêter le moteur, indépendamment de son statut précédent
  if (digitalRead(CONTROLLINO_A4)) {
    iStatut = 0; // Statut Moteur 0 - arrêt
    digitalWrite(CONTROLLINO_D0, LOW); // tous les contacteurs éteints
    digitalWrite(CONTROLLINO_D1, LOW); // tous les contacteurs éteints
    digitalWrite(CONTROLLINO_D2, LOW); // tous les contacteurs éteints
    delay(5000); // attendre jusqu'à ce que le moteur soit complètement arrêté
  }
}
