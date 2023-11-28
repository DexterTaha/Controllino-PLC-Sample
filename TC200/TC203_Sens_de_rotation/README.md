<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/203.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 203 a été développé dans le but de simuler le fonctionnement d'un moteur triphasé en rotation horaire ou antihoraire. La tâche vise à fournir une expérience pratique de la mise en œuvre du contrôle de la direction de rotation d'un moteur, avec des fonctionnalités pour démarrer, arrêter et changer la direction de rotation après une pause spécifiée.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  1. Commande de la Direction de Rotation (Tâche unique): La tâche implique que le moteur soit démarré en direction horaire avec le bouton A1 et en direction antihoraire avec le bouton A2. Le moteur peut être arrêté avec le bouton A4 (contact normalement fermé). La direction de rotation ne peut être modifiée qu'après l'arrêt du moteur via le bouton-poussoir A4 et après une pause de 5 secondes. Cela garantit que le moteur ne peut pas être commuté directement d'une direction de rotation à l'autre.<br>
  Le code TC203_Sens_de_rotation.ino fournit une solution complète pour cette tâche.
<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des boutons pour les entrées A1, A2 et A4, ainsi que des sorties D1 et D2 pour visualiser la direction de rotation dans les sens horaire et antihoraire. Cette configuration permet aux participants de comprendre la mise en œuvre du contrôle de la direction de rotation d'un moteur triphasé, y compris les fonctionnalités de démarrage, d'arrêt et de changement de direction.
</p>
