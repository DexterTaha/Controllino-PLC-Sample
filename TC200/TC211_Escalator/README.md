<p align="center">
<img width="700" height="" src="https://github.com/DexterTaha/Controllino-PLC-Sample/blob/main/Training%20Card%20Picture/211.jpg">
</p>
<h2>Description de project</h2>
<p>
  Le projet TC 211 a été développé dans le but de simuler un escalier roulant. La tâche consiste à activer et désactiver l'escalier roulant via un interrupteur (entrée A0). Le moteur de l'escalier roulant est contrôlé par la sortie D3. Un capteur de barrière lumineuse à l'entrée A2 au bas de l'escalier roulant active le moteur pendant 10 secondes, après quoi il s'arrête à nouveau. En cas d'arrêt d'urgence (interrupteur d'arrêt d'urgence à l'entrée A1 ou A7) ou si le capteur (entrée A6) signale une courroie cassée, le moteur est immédiatement éteint, et une alarme est émise. Le bouton à l'entrée A4 réinitialise cette défaillance après qu'elle a été résolue.
</p>
<h2>Tâches Spécifiques</h2>
<p>
  La tâche implique la simulation d'un escalier roulant avec un ensemble de fonctionnalités spécifiques :<br>
- Activation/désactivation de l'escalier roulant avec un interrupteur (A0).<br>
- Contrôle du moteur de l'escalier roulant avec la sortie D3.<br>
- Activation du moteur par un capteur de barrière lumineuse pendant 10 secondes.<br>
- Arrêt d'urgence immédiat en cas d'activation d'un interrupteur d'arrêt d'urgence (A1 ou A7) ou en cas de détection d'une courroie cassée (A6).<br>
- Émission d'une alarme visuelle et sonore en cas d'arrêt d'urgence ou de détection d'une courroie cassée.<br>
- Réinitialisation de la défaillance avec un bouton après résolution du problème.<br>
  Le code TC211_Escalator.ino fournit une solution complète pour cette tâche.<br>
</p>
<h2>Capteurs/Actionneurs</h2>
<p>
  Les composants du projet comprennent des entrées pour l'interrupteur de l'escalier roulant (A0), l'arrêt d'urgence (A1 ou A7), la barrière lumineuse (A2), le bouton de réinitialisation d'alarme (A4) et le capteur de courroie cassée (A6). Les sorties incluent la visualisation de l'escalier roulant (D0), l'alarme visuelle/sonore (D2) et le contrôle du moteur (D3). Cette configuration permet aux participants de comprendre la mise en œuvre de la simulation d'un escalier roulant avec des fonctionnalités de sécurité et de contrôle.
</p>
