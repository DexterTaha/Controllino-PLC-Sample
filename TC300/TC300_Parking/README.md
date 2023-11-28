<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/300.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 300 a été développé dans le but de contrôler les feux de signalisation pour un parking à plusieurs étages avec 20 places de stationnement. Le contrôle des feux de signalisation à l'entrée doit indiquer si des places de stationnement sont encore disponibles. Le compteur interne des places de stationnement doit être manuellement modifiable en cas de comptage défectueux.
</p>
<h2>Tâches Spécifiques</h2>
<p>
 La tâche implique la mise en place d'un système de contrôle de feux de signalisation pour un parking à plusieurs étages avec les fonctionnalités suivantes :<br>
- Utilisation de barrières lumineuses à l'entrée (A0) et à la sortie (A7) pour enregistrer le nombre de véhicules dans le parking.<br>
- Changement des feux de signalisation à l'entrée en fonction de l'occupation du parking (feu vert si des places sont disponibles, feu rouge si le parking est complet).<br>
- Possibilité de réinitialiser manuellement le compteur des places de stationnement (A1).<br>
- Possibilité d'ajuster manuellement le compteur des places de stationnement (A2).<br>
  Le code TC300_Parking.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des entrées pour les barrières lumineuses à l'entrée (A0) et à la sortie (A7), ainsi que des boutons pour réinitialiser le compteur (A1) et ajuster manuellement le compteur (A2). Les sorties comprennent la visualisation des feux de signalisation à l'entrée (D0 et D1). Cette configuration permet aux participants de comprendre la mise en œuvre du contrôle de feux de signalisation pour un parking avec gestion du compteur des places de stationnement.
</p>
