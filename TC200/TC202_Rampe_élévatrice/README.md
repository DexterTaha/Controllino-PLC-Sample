<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/202.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 202 a été développé dans le but de simuler la fonction d'une plateforme élévatrice, par exemple, dans un atelier de réparation automobile. La tâche vise à fournir une expérience pratique de la simulation du fonctionnement d'une plateforme élévatrice, avec des fonctionnalités pour allumer/éteindre, monter et descendre la plateforme. Le projet intègre également des interrupteurs de fin de course pour limiter les déplacements de la plateforme.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  1. Simulation de la Plateforme Élévatrice (Tâche unique): La tâche consiste à mettre la plateforme élévatrice en service avec l'interrupteur A0. La plateforme peut être allumée ou éteinte avec cet interrupteur. Lorsque le bouton A1 est enfoncé, la plateforme monte, et lorsqu'on appuie sur le bouton A2, elle descend à nouveau. Le moteur est contrôlé avec les sorties D2 ou D3, où D2 signifie "la plateforme monte" et D3 "la plateforme descend". Les interrupteurs de fin de course A4 et A5 limitent les déplacements de la plateforme vers le haut et vers le bas respectivement.<br>
  Le code TC202_Rampe_élévatrice.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des interrupteurs pour les entrées A0, A1, A2, A4 et A5, ainsi que des sorties D2 et D3 pour visualiser le contrôle du moteur, indiquant si la plateforme monte ou descend. Cette configuration permet aux participants de comprendre la mise en œuvre de la simulation d'une plateforme élévatrice avec des fonctionnalités de contrôle détaillées.
</p>
