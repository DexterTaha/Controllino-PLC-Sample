<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/309.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 309 simule le contrôle d'un système de chauffage pour une maison, combinant les fonctionnalités des projets TC 207 et TC 208. Cela reflète une application plus complexe où le chauffage de l'eau pour le chauffage central et le chauffage individuel d'une pièce sont intégrés dans un seul système.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche spécifique de ce projet est la suivante :<br>
- La température de la pièce est mesurée par un capteur de température (A6), tandis que la température de l'eau de la chaudière est mesurée par un autre capteur (A7).<br>
- Le chauffage central est activé/désactivé par un interrupteur (A0), et son état est signalé à la sortie D0.<br>
- La production d'eau chaude est contrôlée par le brûleur, activé à une température inférieure à 60°C et désactivé à 80°C. Une alarme est déclenchée en cas de surchauffe.<br>
- La pompe de circulation pour le chauffage de la pièce est activée lorsque la température réelle de la pièce tombe en dessous de 20°C.<br>
  Le code TC309_Chauffage_Maison.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants principaux de ce projet comprennent des capteurs de température pour mesurer la température de la pièce (A6) et de l'eau de la chaudière (A7), un interrupteur pour activer/désactiver le chauffage central (A0), un bouton pour réinitialiser l'alarme (A1), et des sorties pour signaler l'état du chauffage central (D0), du brûleur (D1), de l'alarme (D2), et de la pompe de circulation (D3).
</p>
