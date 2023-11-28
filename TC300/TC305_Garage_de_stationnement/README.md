<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/305.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 305 a été conçu pour simuler le contrôle d'une porte de garage avec une seule voie d'entrée et de sortie, utilisant un feu de circulation pour sécuriser la direction opposée. L'objectif est de garantir un fonctionnement sécurisé de la porte, en évitant les accidents potentiels lors de l'entrée ou de la sortie d'un véhicule.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche spécifique implique les étapes suivantes :<br>
- Un bouton (A0) situé à l'entrée signale la demande d'entrée au PLC.<br>
- Avant l'ouverture de la porte, le feu de circulation (D3) à l'intérieur du parking est mis au rouge.<br>
- La sortie D1 contrôle le moteur pour ouvrir la porte, et le bouton de fin de course A3 signale lorsque la porte est complètement ouverte.<br>
- La porte reste ouverte pendant 30 secondes avant de se refermer automatiquement.<br>
- Avant la fermeture de la porte, le feu de circulation (D0) à l'entrée est également mis au rouge.<br>
- La sortie D2 contrôle le moteur pour fermer la porte, et le bouton de fin de course A4 signale que la porte est complètement fermée.<br>
  Les mêmes règles s'appliquent pour la sortie, où la demande de sortie est effectuée via le bouton A6.<br>
  Le code TC305_Garage_de_stationnement.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent un bouton de demande d'entrée (A0), des boutons de fin de course pour l'ouverture (A3) et la fermeture (A4) de la porte, un bouton de demande de sortie (A6), des sorties pour contrôler le feu de circulation à l'entrée (D0, D3) et le moteur pour ouvrir/fermer la porte (D1, D2).
</p>
