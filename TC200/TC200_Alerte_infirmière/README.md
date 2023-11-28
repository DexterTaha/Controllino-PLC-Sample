<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/200.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 200 a été élaboré dans le but de simuler un système d'appel infirmier pour une chambre de trois lits dans un hôpital. Chaque patient peut déclencher une alarme depuis son lit, et un message d'alarme est émis dans le couloir. La tâche de niveau 200 vise à fournir une expérience pratique de la mise en œuvre d'un système d'appel infirmier.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  1. Appel Infirmier (Tâche unique): La tâche consiste à générer une alarme à la sortie D2 en utilisant trois boutons d'entrée (A3, A5, A7), chacun associé à un patient spécifique dans la chambre. L'alarme reste active jusqu'à ce qu'elle soit réinitialisée via le bouton A1 à l'entrée de la chambre.<br>
  Le code TC200_Alerte_infirmière.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des boutons pour les entrées A1, A3, A5 et A7, ainsi que la sortie D2 qui visualise le message d'alarme. En plus de l'alarme visuelle, un buzzer peut également être activé pour une alarme acoustique. Cette configuration permet aux participants de comprendre la mise en œuvre d'un système d'appel infirmier.
</p>
