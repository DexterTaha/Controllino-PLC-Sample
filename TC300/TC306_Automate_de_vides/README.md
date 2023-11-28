<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/306.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 306 simule le contrôle d'une machine de consigne pour bouteilles de boissons. Ce type de système est couramment utilisé dans de nombreux pays où une consigne est prélevée sur les bouteilles de boissons, et cette consigne est remboursée lorsqu'une bouteille est retournée via une machine automatique.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche spécifique implique les étapes suivantes :<br>
- La machine de consigne est activée avec le commutateur A0.<br>
- Lorsqu'une bouteille est insérée dans la machine, elle est détectée par la barrière lumineuse A1.<br>
- La bouteille est transportée par le tapis roulant 1 (sortie moteur D0) jusqu'à ce qu'elle soit détectée par la barrière lumineuse A2.<br>
- Le moteur (D0) est arrêté et le scanner de code-barres est activé à la sortie D1.<br>
- Si un code-barres valide est reconnu par le scanner, cela est signalé à l'entrée A3.<br>
- La bouteille est ensuite transportée plus loin par le tapis roulant 2 (sortie moteur D2) jusqu'à ce qu'elle soit détectée par la barrière lumineuse A5.<br>
- Le tapis roulant 2 est arrêté et la presse à bouteilles (sortie D3) est activée. La presse à bouteilles prend 5 secondes, puis le moteur (D2) du tapis roulant 2 est redémarré. Le tapis roulant continue de fonctionner jusqu'à ce que la bouteille pressée ait quitté la barrière lumineuse (A5).<br>
  Le code TC306_Automate_de_vides.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent un commutateur pour activer la machine (A0), des boutons pour les barrières lumineuses (A1, A2, A5) et le scanner de code-barres (A3), des sorties pour les moteurs de tapis roulant (D0, D2) et la presse à bouteilles (D3), et une sortie pour le scanner de code-barres (D1).
</p>
