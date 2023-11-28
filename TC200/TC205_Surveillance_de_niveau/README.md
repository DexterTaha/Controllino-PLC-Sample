<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/205.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 205 a été développé dans le but de simuler le remplissage d'un réservoir à l'aide de deux pompes et d'un interrupteur à flotteur servant de protection contre le débordement. La tâche vise à fournir une expérience pratique de la mise en œuvre du contrôle du niveau de remplissage d'un réservoir, intégrant des fonctionnalités telles que le démarrage et l'arrêt du remplissage, la gestion de deux pompes, et la détection de niveaux critiques.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  1. Surveillance du Niveau (Tâche unique): La tâche implique de démarrer le remplissage du réservoir avec le bouton A0, pouvant être arrêté à tout moment avec le bouton A1 (contact normalement fermé). Le remplissage est effectué jusqu'à 80% (capteur A6) avec deux pompes (sorties D0 et D1), puis jusqu'à 100% (capteur A7) avec une seule pompe (sortie D0). Si le niveau dans le réservoir tombe en dessous de 10% (capteur A5), cela est signalé à la sortie D3. Un nouveau remplissage du réservoir doit être démarré avec le bouton A0.<br>
  Le code TC205_Surveillance_de_niveau.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des boutons pour les entrées A0, A1, A5, A6 et A7, ainsi que des sorties D0, D1 et D3 pour visualiser le fonctionnement des pompes et l'indicateur de niveau. Cette configuration permet aux participants de comprendre la mise en œuvre du contrôle du niveau de remplissage d'un réservoir avec des fonctionnalités détaillées.
</p>
