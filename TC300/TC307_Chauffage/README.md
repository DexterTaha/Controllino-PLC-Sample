<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/307.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 307 simule le contrôle d'un système de chauffage, en mettant particulièrement l'accent sur la charge de la chaudière d'eau chaude. Cela correspond au fonctionnement typique d'un système de chauffage conventionnel dans les bâtiments résidentiels et commerciaux, où la chaleur est générée par la combustion de combustibles tels que le pétrole, le gaz ou les granulés.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche spécifique de ce projet est la suivante :<br>
- Le système de chauffage est activé ou désactivé de manière centralisée avec le commutateur à l'entrée A0.<br>
- L'opération de chauffage est signalée à la sortie D0.<br>
- La production d'eau chaude est gérée par le brûleur, contrôlé par la sortie D1. Le processus de chauffage démarre dès que la température dans la chaudière (mesurée à l'aide du capteur A7) descend en dessous de 60°C. Le brûleur s'éteint lorsque la température atteint 80°C.<br>
- Pour des raisons de sécurité, la chaudière est équipée d'un interrupteur de température excessive (réalisé sous forme d'un contact normalement fermé) connecté à l'entrée A3. En cas de température excessive, le brûleur doit être immédiatement désactivé, et une alarme est générée à la sortie D2.<br>
- Après la résolution du problème de température excessive, l'alarme peut être réinitialisée manuellement via le bouton-poussoir à l'entrée A4. Jusqu'à ce que cela soit fait, le brûleur doit rester désactivé de manière sécurisée.<br>
  Le code TC307_Chauffage.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants principaux de ce projet incluent un commutateur pour activer le système de chauffage (A0), un bouton pour l'interrupteur de température excessive (A3), un bouton pour la réinitialisation de l'alarme (A4), un capteur de température dans la chaudière (A7), et des sorties pour signaler l'état du chauffage (D0), l'état du brûleur (D1), et l'alarme de température excessive (D2).
</p>
