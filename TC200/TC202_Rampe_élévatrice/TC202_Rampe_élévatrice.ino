#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC202_Rampe_élévatrice
//

// Définition des variables
bool bMarche;           // Rampe élévatrice allumée
bool bMonter;           // monter
bool bDescendre;        // descendre
bool bFinHaut;          // atteint le niveau supérieur
bool bFinBas;           // atteint le niveau inférieur

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Allumage / Extinction
  if (digitalRead(CONTROLLINO_A0))
    bMarche = true;
  else
    bMarche = false;

  // Détection de la fin supérieure
  if (digitalRead(CONTROLLINO_A4))
  {
    bFinHaut = true;
  }
  else
  {
    bFinHaut = false;
  }

  // Détection de la fin inférieure
  if (digitalRead(CONTROLLINO_A5))
  {
    bFinBas = true;
  }
  else
  {
    bFinBas = false;
  }

  // Monter
  if (digitalRead(CONTROLLINO_A1) && !bFinHaut && bMarche)
  {
    bMonter = true;
  }
  else
  {
    bMonter = false;
  }

  // Descendre
  if (digitalRead(CONTROLLINO_A2) && !bFinBas && bMarche)
  {
    bDescendre = true;
  }
  else
  {
    bDescendre = false;
  }

  // Activer le moteur
  if (bMonter && !bDescendre)
  {
    digitalWrite(CONTROLLINO_D3, LOW);
    digitalWrite(CONTROLLINO_D2, HIGH);
  }
  else
  {
    if (bDescendre && !bMonter)
    {
      digitalWrite(CONTROLLINO_D2, LOW);
      digitalWrite(CONTROLLINO_D3, HIGH);
    }
    else
    {
      digitalWrite(CONTROLLINO_D2, LOW);
      digitalWrite(CONTROLLINO_D3, LOW);
    }
  }
}
