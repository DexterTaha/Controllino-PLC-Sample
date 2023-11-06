#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC105_Circuit_de_croisement
//

// Définition des variables
int iDelai = 200;
bool bStatut;
bool bBascule;

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Circuit_de_croisement

  if (digitalRead(CONTROLLINO_A0) && (bBascule == false)) {
    bStatut = !bStatut;
    bBascule = true;
  }
  if (digitalRead(CONTROLLINO_A1) && (bBascule == false)) {
    bStatut = !bStatut;
    bBascule = true;
  }
  digitalWrite(CONTROLLINO_D0, bStatut);
  if ((digitalRead(CONTROLLINO_A0) == false) && (digitalRead(CONTROLLINO_A1) == false))
    bBascule = false;

  delay(50);
}
