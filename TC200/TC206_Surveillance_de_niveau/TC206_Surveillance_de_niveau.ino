#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC206_Surveillance_de_niveau
//

// Définition des variables
int iValeur;           // Niveau de remplissage
                       // 0 - 1024 équivaut à 0V - 24V
                       // La valeur analogique sur le tableau de formation est de 0V - 10V
                       // Valeurs utilisables
                       //   100% -> 320
                       //    80% -> 260
                       //    10% -> 32
bool bDépassement;     // false - sous le niveau, true - dépassement
bool bRemplissage = false; // true - En marche, false - Arrêt

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
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
  // Lire le niveau de carburant depuis le capteur analogique
  iValeur = analogRead(CONTROLLINO_A7);

  // Vérifier le dépassement
  if (digitalRead(CONTROLLINO_A5) == HIGH) {
    bDépassement = true;
    bRemplissage = false;
  } else {
    bDépassement = false;
  }

  // Bouton poussoir pour démarrer le remplissage
  if (digitalRead(CONTROLLINO_A0) == HIGH)
    bRemplissage = true;

  // Bouton poussoir pour arrêter le remplissage
  if (digitalRead(CONTROLLINO_A1) == LOW)
    bRemplissage = false;

  // Démarrer/arrêter la pompe1 et/ou la pompe2
  if (bRemplissage && !bDépassement) {
    if (iValeur > 320) { // Valeur au-dessus de 1000 - arrêter les deux pompes
      digitalWrite(CONTROLLINO_D0, LOW);
      digitalWrite(CONTROLLINO_D1, LOW);
      bRemplissage = false;
    } else {
      if (iValeur < 260) { // Valeur en dessous de 800 - démarrer les deux pompes
        digitalWrite(CONTROLLINO_D0, HIGH);
        digitalWrite(CONTROLLINO_D1, HIGH);
      } else { // Valeur entre 800 et 1000 - laisser la pompe1 en marche
        digitalWrite(CONTROLLINO_D0, HIGH);
        digitalWrite(CONTROLLINO_D1, LOW);
      }
    }
  } else { // En cas de dépassement, arrêter les deux pompes
    digitalWrite(CONTROLLINO_D0, LOW);
    digitalWrite(CONTROLLINO_D1, LOW);
    bRemplissage = false;
  }

  // Signal d'ALARME
  if (bDépassement)
    digitalWrite(CONTROLLINO_D2, HIGH);
  else
    digitalWrite(CONTROLLINO_D2, LOW);

  // Signal <10%
  if (iValeur < 32)
    digitalWrite(CONTROLLINO_D3, HIGH);
  else
    digitalWrite(CONTROLLINO_D3, LOW);
}
