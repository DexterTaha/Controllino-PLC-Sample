#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC102_Bascule_RelayTempête
//

// Définition des variables
bool bRS1;
bool bRS2;
bool bBasculerUneFois;

//
// Configuration
//
void setup() {
  // Définir les broches en tant qu'entrées ou sorties
  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
}

//
// Boucle
//
void loop() {
  // Bascule

  // S R
  // 0 0    x
  // 0 1    0
  // 1 0    1
  // 1 1    0

  if (digitalRead(CONTROLLINO_A0))
    bRS1 = true;
  if (digitalRead(CONTROLLINO_A1))
    bRS1 = false;

  digitalWrite(CONTROLLINO_D0, bRS1);

  // RelaisTempête

  if (digitalRead(CONTROLLINO_A3) && (bBasculerUneFois == false)) {
    bRS2 = !bRS2;
    bBasculerUneFois = true;
    delay(50);
  }
  if (!digitalRead(CONTROLLINO_A3) && (bBasculerUneFois == true)) {
    bBasculerUneFois = false;
    delay(50);
  }
  if (digitalRead(CONTROLLINO_A4))
    bRS2 = true;
  if (digitalRead(CONTROLLINO_A5))
    bRS2 = false;

  digitalWrite(CONTROLLINO_D1, bRS2);
}
