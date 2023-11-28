<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/310.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 310 simule le contrôle automatique et manuel d'un auvent en fonction des conditions météorologiques, utilisant des capteurs analogiques pour mesurer la luminosité (rayonnement solaire) et la vitesse du vent. Le système permet également un contrôle manuel de l'auvent.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche spécifique de ce projet est la suivante :<br>
- Le mode automatique est activé/désactivé par un interrupteur (A0).<br>
- En mode automatique, l'auvent s'ouvre automatiquement lorsque la luminosité mesurée (capteur A6) dépasse 50%. Toutefois, le capteur de vent (A7) a la priorité. Si la vitesse du vent mesurée dépasse 50%, l'auvent doit se fermer automatiquement.<br>
- En mode manuel, l'auvent peut être ouvert ou fermé à l'aide de deux boutons (A1 et A2).<br>
- L'ouverture et la fermeture automatiques sont effectuées par le moteur, contrôlé par les sorties D2 (ouvrir) et D3 (fermer).<br>
- Les interrupteurs de fin de course (A3 pour ouvrir et A4 pour fermer) indiquent lorsque l'auvent atteint sa position maximale ou minimale.<br>
- Les sorties D0 et D1 visualisent l'état actuel de l'auvent (ouvert ou fermé).<br>
  Le code TC310_Controle_store.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants principaux de ce projet comprennent des interrupteurs pour activer/désactiver le mode automatique (A0), des boutons pour le contrôle manuel (A1 et A2), des interrupteurs de fin de course pour détecter les positions maximale et minimale de l'auvent (A3 et A4), des capteurs analogiques pour mesurer la luminosité (A6) et la vitesse du vent (A7), et des sorties pour contrôler le moteur de l'auvent (D2 et D3) ainsi que pour visualiser l'état de l'auvent (D0 et D1).
</p>
