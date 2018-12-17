<h1> Rapport du 17/12/12:</h1>

<p>
<h2>Programmation du réveil</h2>
Durant la dernière séance, nous avons réussi à afficher l'heure sur un écran lcd grâce au module RTC. J'ai cherché comment modifier notre programme afin qu'il puisse fonctionner comme un réveil. Pour cela, j'ai finalement juste choisi une heure aléatoire et j'ai demandé à l'arduino d'afficher un message sur le moniteur à l'heure voulu.
J'ai ensuite voulu utiliser un buzzer pour qu'à l'heure voulu, le buzzer émette un son. Cependant je n'ai pas réussi à faire fonctionner le buzzer. J'ai essayé de le faire marcher simplement : je l'ai branché sur une I/O, je l'ai reglé en OUTPUT. J'ai essayé d'utiliser la fonction tone (fonction qui génère une onde carré) de cette façon : tone(I/O, fréquence, durée). Cela n'a pas fonctionné. Je n'ai pas réussi à trouver la source du problème pendant cette séance.

<h2>Réveil bluetooth</h2>
Nous voulons que notre réveil soit programmable sur le téléphone. Kilian s'est occupé de cette partie mais arduino ne fonctionnait pas sur son ordinateur aujourd'hui, on a donc testé son programme sur le mien. Son téléphone était connecté à l'arduino par bluetooth, l'heure qu'il choisissait sur son téléphone s'affichait sur le moniteur.

<h2>Prochaine séance...</h2>
Je voulais, après avoir fait fonctionner le buzzer, utiliser un bouton poussoir afin que le buzzer émette un son à l'heure choisit, puis ne s'arrête qu'une fois que l'on appuie sur le bouton poussoir. 
</p>
