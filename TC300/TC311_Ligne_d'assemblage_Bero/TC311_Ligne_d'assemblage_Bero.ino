#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TLigne d'assemblage Bero (TC311)
//

// Définition des variables

bool bOn;                          // Marche/Arrêt
bool bVersLaGauche;                // aller vers la gauche
bool bVersLaDroite;                // aller vers la droite
int iCompteur;                     // Compte le nombre d'impulsions par seconde
int iDernierCompteur = 3;          // Compteur depuis la dernière seconde
unsigned long tempsPrecedent = 0;  // Millisecondes précédentes
unsigned long tempsActuel;         // Millisecondes actuelles

//
// Configuration
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);

pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);

// Gestionnaire d'interruption
pinMode(CONTROLLINO_IN0, INPUT);
attachInterrupt(digitalPinToInterrupt(CONTROLLINO_IN0), compter, RISING);
// LOW      pour déclencher l'interruption chaque fois que la broche est basse,
// CHANGE   pour déclencher l'interruption chaque fois que la broche change d'état
// RISING   pour déclencher l'interruption lorsque la broche passe de basse à haute,
// FALLING  pour déclencher l'interruption lorsque la broche passe de haute à basse.

}


//
// Boucle
//
void loop() {

// Temps actuel
tempsActuel = millis();

// Attribution de iDernierCompteur = iCompteur  
if (tempsActuel - tempsPrecedent >= 1000 ) 
{
    // Chaque changement de front déclenche une interruption
    // Par conséquent, chaque impulsion est comptée deux fois
    iDernierCompteur = iCompteur;
    iCompteur = 0;
    tempsPrecedent = tempsActuel;
}

// Marche/Arrêt
if ( digitalRead (CONTROLLINO_A0) )
    bOn = true;
  else
    bOn = false;
  

// Détection d'une course vers la droite
if ( iDernierCompteur < 300 ) 
{
    bVersLaGauche = false;
    bVersLaDroite = true;
}

// Détection d'une course vers la gauche
if ( iDernierCompteur > 700 ) 
{
    bVersLaGauche = true;
    bVersLaDroite = false;
}

// Démarrer le moteur dans la direction requise
if ( bVersLaGauche && bOn ) 
{
    digitalWrite ( CONTROLLINO_D3, LOW);
    digitalWrite ( CONTROLLINO_D2, HIGH);
}
else if ( bVersLaDroite && bOn ) 
{
    digitalWrite ( CONTROLLINO_D2, LOW);
    digitalWrite ( CONTROLLINO_D3, HIGH);
}
else if (!bOn)
{
    digitalWrite ( CONTROLLINO_D2, LOW);
    digitalWrite ( CONTROLLINO_D3, LOW);
}

} // Boucle

// Fonction pour compter les impulsions
void compter() {
 iCompteur++;
}
