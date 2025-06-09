Documentation : Interface utilisateur et son (Membre 2)
Rôle

Implémenter GameView pour le rendu graphique (menu, HUD, tours, ennemis).
Gérer les événements clavier/souris (navigation menu, paramètres).
Implémenter le son (généré avec SFML, toggle avec 'S', volume ajustable).

Implémentation

Menu principal : Rectangles blancs avec texte pour "Nouvelle Partie", "Score", "Hall of Fame", "Paramètres", "Quitter" (touches 1-5).
Paramètres : Sous-menu avec "Son" (slider bleu), "Résolution" (800x600), "Retour".
HUD : Rectangle gris en haut avec Score et HP en texte.
Arrière-plan : Rectangle vert clair (50, 150, 50).
Tours : Rectangles (30x30, vert pour BasicTower, bleu pour SniperTower).
Ennemis : Carrés rouges (20x20) avec barres de vie vertes.
Son : Onde sinusoïdale (440 Hz, 100ms) pour tirs, activé/désactivé avec 'S'.

Plan exécuté

Jour 1 : Configuration et structure de base.
Jour 2 : Menu principal.
Jour 3 : Paramètres (Son, Résolution).
Jour 4 : HUD et arrière-plan.
Jour 5 : Tours et ennemis.
Jour 6 : Son généré et tests.
Jour 7 : Finalisation et documentation.

Problèmes rencontrés

Son généré : Qualité limitée, à améliorer avec des fréquences variables.
Rendu : Performances à tester avec beaucoup d’ennemis.

Captures d’écran

[Menu principal]
[Paramètres avec slider]
[Jeu avec HUD, tours, ennemis]

