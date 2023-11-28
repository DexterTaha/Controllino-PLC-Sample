<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/201.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 201 a été élaboré dans le but de construire un système de commande d'éclairage pour un long couloir, avec la possibilité d'allumer les lumières à chaque porte d'appartement via un bouton-poussoir. Après un laps de temps spécifié, deux lampes doivent rester allumées brièvement en tant qu'éclairage d'urgence. La tâche de niveau 201 vise à fournir une expérience pratique de la création d'un système de contrôle d'éclairage complexe pour un couloir.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  1. Contrôle d'Éclairage du Couloir (Tâche unique): La tâche implique que les boutons aux entrées A0, A2, A4 et A6 activent l'éclairage du couloir aux sorties D0 à D3, simulant ainsi l'éclairage du couloir. Après 10 secondes, seules les sorties D1 et D5 doivent être activées pendant 5 secondes en tant qu'éclairage d'urgence. Ensuite, toutes les lampes doivent être éteintes.<br>
  Le code TC201_Lumière_du_couloir.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des boutons pour les entrées A0, A2, A4 et A6, ainsi que des sorties D0 à D3 pour visualiser l'éclairage du couloir. Les sorties D1 et D5 sont utilisées pour visualiser l'éclairage d'urgence. Cette configuration permet aux participants de comprendre la mise en œuvre d'un système de contrôle d'éclairage complexe avec des fonctionnalités d'éclairage d'urgence.
</p>
