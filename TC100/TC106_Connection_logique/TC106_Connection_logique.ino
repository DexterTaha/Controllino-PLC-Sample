#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC106_Connection_logique
//

// Définition des variables
bool bET;
bool bOU;
bool bNON;

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Connection_logique

  if ((digitalRead(CONTROLLINO_A0) == true) && (digitalRead(CONTROLLINO_A1) == true))
    bET = true;
  else
    bET = false;
  digitalWrite(CONTROLLINO_D0, bET);

  if ((digitalRead(CONTROLLINO_A3) == true) || bET)
    bOU = true;
  else
    bOU = false;
  digitalWrite(CONTROLLINO_D1, bOU);

  bNON = !bOU;
  digitalWrite(CONTROLLINO_D2, bNON);
}
