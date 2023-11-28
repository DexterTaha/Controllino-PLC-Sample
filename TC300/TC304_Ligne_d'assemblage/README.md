<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/304.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 304 a été développé dans le but de simuler le contrôle d'une ligne de montage ou d'un convoyeur avec fonction d'arrêt d'urgence. La tâche spécifique consiste à transporter un colis en marche arrière sur un tapis roulant (de gauche à droite et vice versa), avec la mise en œuvre d'une fonction d'arrêt d'urgence pour assurer la sécurité.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche spécifique comprend les éléments suivants :<br>
- Allumage/arrêt du convoyeur avec l'interrupteur (A0).<br>
- Détection d'un colis entrant avec la barrière lumineuse à gauche (A2) et à droite (A6).<br>
- Contrôle du moteur du tapis roulant avec les sorties D0 (direction de transport à gauche) et D1 (direction de transport à droite).<br>
- Fonction d'arrêt d'urgence avec le bouton d'arrêt d'urgence (A3), entraînant l'arrêt immédiat du tapis roulant et la génération d'une alarme (D2).<br>
- Réinitialisation de l'alarme avec le bouton (A4).<br>
  Le code TC304_Ligne_d'assemblage.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent un interrupteur pour allumer/éteindre le convoyeur (A0), des barrières lumineuses pour détecter l'arrivée d'un colis à gauche (A2) et à droite (A6), un bouton d'arrêt d'urgence (A3), un bouton de réinitialisation d'alarme (A4), et des sorties pour contrôler le moteur du tapis roulant (D0 et D1) ainsi que pour signaler l'alarme (D2).
</p>
