#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC200_Alerte_infirmière
//

// Définition des variables
bool bAlarme = false;

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);
  pinMode(CONTROLLINO_A7, INPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Réinitialisation de l'ALARME
  if (digitalRead(CONTROLLINO_A1) == true)
    bAlarme = false;

  // Activation de l'Alarme
  if ((digitalRead(CONTROLLINO_A3) == true) || (digitalRead(CONTROLLINO_A5) == true) || (digitalRead(CONTROLLINO_A7) == true))
    bAlarme = true;

  // Sortie de l'ALARME
  digitalWrite(CONTROLLINO_D2, bAlarme);
}
