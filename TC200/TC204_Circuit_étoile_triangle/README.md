<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/204.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 204 a été conçu pour simuler le fonctionnement d'un moteur triphasé dans un circuit étoile-triangle. La tâche vise à fournir une expérience pratique de la mise en œuvre du contrôle de démarrage et d'arrêt d'un moteur triphasé, ainsi que du basculement entre les modes étoile et triangle après une période spécifiée.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  1. Circuit Étoile-Triangle (Tâche 1): La première tâche implique de démarrer le moteur triphasé en circuit étoile en appuyant sur le bouton A0. Cela se fait en contrôlant simultanément les sorties D0 et D1. Au plus tôt 3 secondes après, le moteur peut être basculé en mode triangle en appuyant sur le bouton A2. Pour ce faire, la sortie D1 doit d'abord être éteinte, et la sortie D2 doit être allumée seulement après. Le moteur peut être arrêté à tout moment en appuyant sur le bouton A4, éteignant toutes les sorties. Le code TC204_Circuit_étoile_triangle.ino fournit une solution complète pour cette tâche.<br>
  2. Circuit Étoile-Triangle avec Démarrage Automatique (Tâche 2): La deuxième tâche consiste à démarrer le moteur triphasé en mode étoile en appuyant sur le bouton A0. Cela se fait en contrôlant simultanément les sorties D0 et D1. Après 10 secondes, le moteur doit basculer automatiquement en mode triangle. Pour ce faire, la sortie D1 doit d'abord être éteinte, et la sortie D2 doit être allumée seulement après. Le moteur peut être arrêté à tout moment en appuyant sur le bouton A4, éteignant toutes les sorties.<br>
  Le code TC204_Circuit_étoile_triangle.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des boutons pour les entrées A0, A2 et A4, ainsi que des sorties D0, D1 et D2 pour visualiser le contrôle des contacteurs principaux, du contacteur étoile et du contacteur triangle. Cette configuration permet aux participants de comprendre la mise en œuvre du contrôle du moteur triphasé dans un circuit étoile-triangle.
</p>
