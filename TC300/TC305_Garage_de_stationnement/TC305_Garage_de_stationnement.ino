#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC305_Garage_de_stationnement
//

// Définition des variables

bool bDemandeEntree;        // demande d'entrée dans le garage
bool bDemandeSortie;        // demande de sortie du garage
bool bFinDeCourseOuvert;    // fin de course, porte du garage ouverte
bool bFinDeCourseFerme;     // fin de course, porte du garage fermée

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

  // Détecter la demande d'entrée
  if (digitalRead(CONTROLLINO_A0))
  {
    bDemandeEntree = true;
  }

  // Détecter la demande de sortie
  if (digitalRead(CONTROLLINO_A6))
  {
    bDemandeSortie = true;
  }

  // Traiter l'ouverture de la porte pour entrée
  if (bDemandeEntree)
  {
    // Passer le feu de signalisation au ROUGE
    digitalWrite(CONTROLLINO_D0, HIGH);
    digitalWrite(CONTROLLINO_D3, HIGH);
    delay(1000);

    // Commencer à ouvrir la porte
    while (digitalRead(CONTROLLINO_A3) == LOW)
    {
      digitalWrite(CONTROLLINO_D1, HIGH);
    }

    // Arrêter l'ouverture de la porte
    digitalWrite(CONTROLLINO_D1, LOW);
    delay(1000);

    // Éteindre le feu de signalisation d'entrée
    digitalWrite(CONTROLLINO_D0, LOW);

    // Temps pour entrer
    delay(5000);

    // Réactiver le feu de signalisation d'entrée
    digitalWrite(CONTROLLINO_D0, HIGH);
    delay(2000);

    // Commencer à fermer la porte
    while (digitalRead(CONTROLLINO_A4) == LOW)
    {
      digitalWrite(CONTROLLINO_D2, HIGH);
    }

    // Arrêter la fermeture de la porte
    digitalWrite(CONTROLLINO_D2, LOW);
    delay(1000);

    // Éteindre le feu de signalisation
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D3, LOW);

    // Réinitialiser la demande d'entrée
    bDemandeEntree = false;
  }

  // Traiter l'ouverture de la porte pour sortie
  if (bDemandeSortie)
  {
    // Passer le feu de signalisation au ROUGE
    digitalWrite(CONTROLLINO_D0, HIGH);
    digitalWrite(CONTROLLINO_D3, HIGH);
    delay(1000);

    // Commencer à ouvrir la porte
    while (digitalRead(CONTROLLINO_A3) == LOW)
    {
      digitalWrite(CONTROLLINO_D1, HIGH);
    }

    // Arrêter l'ouverture de la porte
    digitalWrite(CONTROLLINO_D1, LOW);
    delay(1000);

    // Éteindre le feu de signalisation de sortie
    digitalWrite(CONTROLLINO_D3, LOW);

    // Temps pour sortir
    delay(5000);

    // Réactiver le feu de signalisation de sortie
    digitalWrite(CONTROLLINO_D3, HIGH);
    delay(2000);

    // Commencer à fermer la porte
    while (digitalRead(CONTROLLINO_A4) == LOW)
    {
      digitalWrite(CONTROLLINO_D2, HIGH);
    }

    // Arrêter la fermeture de la porte
    digitalWrite(CONTROLLINO_D2, LOW);
    delay(1000);

    // Éteindre le feu de signalisation
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D3, LOW);

    // Réinitialiser la demande de sortie
    bDemandeSortie = false;
  }

}
