#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC211_Escalator
//

// Définition des variables

bool bAllume = false;                // true-Allumé, false-Éteint
bool bUrgence;                       // true-Urgence, false-OK
bool bDefaillanceCourroie;           // true-défaillance, false-OK
const long iEscalierEnFonctionnement = 5000;  // délai jusqu'à l'arrêt de l'escalier roulant
unsigned long tempsPrecedent = 0;     // millisecondes précédentes stockées
unsigned long tempsActuel;            // millisecondes actuelles

//
// Configuration
//
void setup() {

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A6, INPUT);
  pinMode(CONTROLLINO_A7, INPUT);

  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

  tempsActuel = millis();

  // Bouton pour allumer l'escalier roulant
  if (digitalRead(CONTROLLINO_A0) == HIGH)
    bAllume = true;
  else
    bAllume = false;

  // Réinitialiser l'urgence
  if (digitalRead(CONTROLLINO_A4) == HIGH)
    bUrgence = false;

  // Vérifier l'urgence -> normalement fermée
  if ((digitalRead(CONTROLLINO_A1) == LOW) || (digitalRead(CONTROLLINO_A7) == LOW))
    bUrgence = true;

  // Détecter la défaillance de la courroie -> normalement fermée
  if (digitalRead(CONTROLLINO_A6) == LOW)
  {
    bDefaillanceCourroie = true;
    bUrgence = true;
  }
  else
    bDefaillanceCourroie = false;

  // Démarrer l'escalier roulant avec une barrière de détection lumineuse
  if (bAllume && !bUrgence && (digitalRead(CONTROLLINO_A2) == HIGH))
  {
    digitalWrite(CONTROLLINO_D3, HIGH);
    tempsPrecedent = tempsActuel;
  }

  // Arrêter l'escalier roulant en cas d'urgence ou à la fin du délai
  if (bUrgence || (tempsActuel - tempsPrecedent >= iEscalierEnFonctionnement))
    digitalWrite(CONTROLLINO_D3, LOW);

  // Signal d'ALARME
  if (bUrgence)
    digitalWrite(CONTROLLINO_D2, HIGH);
  else
    digitalWrite(CONTROLLINO_D2, LOW);

  // Signal d'Escalier Roulant Allumé
  if (bAllume)
    digitalWrite(CONTROLLINO_D0, HIGH);
  else
    digitalWrite(CONTROLLINO_D0, LOW);
}
