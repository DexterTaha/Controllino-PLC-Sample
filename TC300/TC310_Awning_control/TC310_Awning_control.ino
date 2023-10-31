#include <SPI.h>
#include <Controllino.h>

//
// Tâche : TC310_Controle_store

// Définition des variables

bool bAuto;           // Mode automatique-vrai, mode manuel-faux
bool bOuverture;        // ouverture manuelle
bool bFermeture;       // fermeture manuelle
bool bFinOuvert;        // fin de course ouvert
bool bFinFermé;       // fin de course fermé
int iVent;           // valeur analogique du vent
int iLuminosité;     // valeur analogique de la luminosité

//
// Configuration
//
void setup() {

pinMode(CONTROLLINO_A0, INPUT);
pinMode(CONTROLLINO_A1, INPUT);
pinMode(CONTROLLINO_A2, INPUT);
pinMode(CONTROLLINO_A3, INPUT);
pinMode(CONTROLLINO_A4, INPUT);
pinMode(CONTROLLINO_A6, INPUT);
pinMode(CONTROLLINO_A7, INPUT);

pinMode(CONTROLLINO_D0, OUTPUT);
pinMode(CONTROLLINO_D1, OUTPUT);
pinMode(CONTROLLINO_D2, OUTPUT);
pinMode(CONTROLLINO_D3, OUTPUT);
}

//
// Boucle
//
void loop() {

// Lire les valeurs analogiques du capteur de vent et de luminosité
iLuminosité = analogRead(CONTROLLINO_A6);
iVent = analogRead(CONTROLLINO_A7);

// Détecter le mode automatique
if (digitalRead(CONTROLLINO_A0))
bAuto = true;
else
bAuto = false;

// Détecter l'ouverture de la fin de course
if (digitalRead(CONTROLLINO_A3))
{
bFinOuvert = true;
}
else
{
bFinOuvert = false;
}

// Détecter la fermeture de la fin de course
if (digitalRead(CONTROLLINO_A4))
{
bFinFermé = true;
}
else
{
bFinFermé = false;
}

// Commutateur d'ouverture manuelle
if (digitalRead(CONTROLLINO_A1))
{
bOuverture = true;
}
else
{
bOuverture = false;
}

// Commutateur de fermeture manuelle
if (digitalRead(CONTROLLINO_A2))
{
bFermeture = true;
}
else
{
bFermeture = false;
}

// Mode automatique ou manuel
if (bAuto)
{
// Mode automatique
// Ouvrir s'il n'y a pas de vent mais du soleil
if ((iVent < 150) && (iLuminosité > 150))
{
bOuverture = true;
bFermeture = false;
}

// Fermer en cas de vent
if (iVent > 150)
{
bFermeture = true;
bOuverture = false;
}

// Fermer en cas d'absence de luminosité
if (iLuminosité < 150)
{
bFermeture = true;
bOuverture = false;
}
}
else
{
// Mode manuel
// Fermer en cas de vent
if (iVent > 150)
{
bFermeture = true;
bOuverture = false;
}
}

// Si les deux ouvertures et fermetures sont activées
if (bOuverture && bFermeture)
{
bFermeture = true;
bOuverture = false;
}

// Contrôle du moteur
if (bOuverture && !bFinOuvert)
{
digitalWrite(CONTROLLINO_D3, LOW);
digitalWrite(CONTROLLINO_D2, HIGH);
}
else if (bFermeture && !bFinFermé)
{
digitalWrite(CONTROLLINO_D2, LOW);
digitalWrite(CONTROLLINO_D3, HIGH);
}
else
{
digitalWrite(CONTROLLINO_D2, LOW);
digitalWrite(CONTROLLINO_D3, LOW);
}

// Signal d'ouverture
if (bFinOuvert)
digitalWrite(CONTROLLINO_D0, HIGH);
else
digitalWrite(CONTROLLINO_D0, LOW);

// Signal de fermeture
if (bFinFermé)
digitalWrite(CONTROLLINO_D1, HIGH);
else
digitalWrite(CONTROLLINO_D1, LOW);

}
