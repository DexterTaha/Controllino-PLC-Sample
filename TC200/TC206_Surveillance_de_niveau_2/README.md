<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/206.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 206 a été développé pour simuler le remplissage d'un réservoir à l'aide de deux pompes, avec un émetteur de valeurs analogiques servant de capteur de niveau et un interrupteur à flotteur servant de protection contre le débordement. L'objectif de cette tâche est de fournir une expérience pratique de la mise en œuvre du contrôle du niveau de remplissage d'un réservoir, en utilisant des capteurs analogiques et numériques, ainsi que la gestion des pompes et des alarmes en cas de débordement.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  1. Surveillance du Niveau avec Capteur Analogique et Interrupteur à Flotteur (Tâche unique): La tâche implique de démarrer le remplissage du réservoir avec le bouton A0, pouvant être arrêté à tout moment avec le bouton A1 (contact normalement fermé). L'émetteur de valeurs analogiques (A7) détecte le niveau dans le réservoir. Le remplissage est effectué jusqu'à 80% avec deux pompes (sorties D0 et D1), puis jusqu'à 100% avec une seule pompe (sortie D0). Si l'interrupteur à flotteur détecte un débordement dans le réservoir, les deux pompes doivent être éteintes. Une alarme est générée à la sortie D2 jusqu'à ce que l'interrupteur à flotteur ne détecte plus de débordement. Si le niveau dans le réservoir tombe en dessous de 10%, cela est signalé à la sortie D3. Un nouveau remplissage du réservoir doit être démarré avec le bouton A0.<br>
  Le code TC206_Surveillance_de_niveau_2.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des boutons pour les entrées A0, A1, l'interrupteur à flotteur pour A5, l'émetteur de valeurs analogiques pour A7, ainsi que des sorties D0, D1, D2 et D3 pour visualiser le fonctionnement des pompes, les alarmes et l'indicateur de niveau. Cette configuration permet aux participants de comprendre la mise en œuvre du contrôle du niveau de remplissage d'un réservoir avec une combinaison de capteurs analogiques et numériques, tout en gérant les pompes et les alarmes associées.
</p>
