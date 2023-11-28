<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/311.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 311 simule le contrôle d'une ligne d'assemblage ou de convoyage utilisant un capteur BERO. L'objectif est de transporter un colis en marche avant et en marche arrière sur un tapis roulant en fonction des signaux générés par le capteur BERO.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche spécifique de ce projet est la suivante :<br>
- La bande transporteuse est activée avec l'interrupteur (A0).<br>
- Un capteur BERO est monté du côté gauche de la bande transporteuse et convertit la distance du colis en fréquence pour l'entrée d'interruption (A3 / IN0) du Controllino.<br>
- À 200 Hz, le colis doit être déplacé vers la droite, et à 800 Hz, vers la gauche.<br>
- La bande transporteuse est entraînée par un moteur, contrôlé par les sorties D2 (direction de déplacement vers la gauche) et D3 (direction de déplacement vers la droite).<br>
  Le code TC311_Ligne_d'assemblage_Bero.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les principaux composants de ce projet comprennent un interrupteur pour activer la bande transporteuse (A0), un capteur BERO pour détecter la position du colis et générer des signaux de fréquence (IN0/A3), et des sorties pour contrôler le moteur de la bande transporteuse (D2 et D3). fonction des signaux du capteur.
</p>
