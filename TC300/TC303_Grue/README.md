<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/303.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 303 a été développé dans le but de simuler le contrôle d'une grue avec surveillance de charge. La mise en œuvre comprend le démarrage/arrêt de la grue, la levée et la descente de la charge, la détection de la position du treuil, la surveillance de la charge, l'arrêt d'urgence, et la réinitialisation de l'alarme.
</p>
<h2>Tâches Spécifiques</h2>
<p>
La tâche spécifique consiste en :<br>
- Allumage/arrêt de la grue avec l'interrupteur (A0), signalé à la sortie D3.<br>
- Levée de la charge avec le bouton (A1) et descente avec le bouton (A2).<br>
- Contrôle du moteur du treuil avec les sorties D0 "Lever la charge" et D1 "Abaisser la charge".<br>
- Détection de la position du treuil avec le capteur (A3), entraînant l'arrêt immédiat du processus de levage s'il est en haut.<br>
- Surveillance de la charge avec le capteur analogique (A7), avec une interruption du processus de levage et déclenchement d'une alarme (D2) si la charge est de 600 kg ou plus.<br>
- Arrêt d'urgence avec le bouton (A5), arrêtant immédiatement tous les mouvements de la grue.<br>
- Indication de l'alarme à la sortie D2, avec possibilité de réinitialisation via le bouton (A4).<br>
  Le code TC303_Grue.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent un interrupteur pour allumer/éteindre la grue (A0), des boutons pour lever (A1) et abaisser (A2) la charge, un capteur pour détecter la position du treuil (A3), un bouton d'arrêt d'urgence (A5), un capteur de charge (A7), et des sorties pour contrôler le moteur du treuil (D0 et D1) ainsi que pour signaler l'état de la grue (D3) et l'alarme (D2).
</p>
