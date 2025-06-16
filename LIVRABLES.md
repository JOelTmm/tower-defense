# LIVRABLES - Projet Tower Defense

## Conformité au cahier des charges

Ce projet respecte intégralement le cahier des charges fourni. Voici le détail des livrables:

## 1. Diagramme de cas d'utilisation ✅
**Fichier**: `docs/UML_Diagrams.md`
- Identification des interactions utilisateur/jeu
- Cas d'utilisation principaux: démarrer, jouer, gérer tours, paramètres, audio
- Relations entre les cas d'utilisation

## 2. Diagramme de classe ✅
**Fichier**: `docs/UML_Diagrams.md`
- Représentation de la structure statique du système
- Hiérarchie des classes avec héritage
- Relations entre classes (composition, agrégation, association)
- Design patterns visualisés

## 3. Architecture MVC ✅
**Description détaillée dans**: `README.md`

### Model (Modèle)
- `Tower.hpp/cpp` - Logique des tours de défense
- `Enemy.hpp/cpp` - Logique des ennemis
- `Map.hpp/cpp` - Gestion de la carte de jeu

### View (Vue)
- `GameView.hpp/cpp` - Interface de jeu principale
- `StartState.hpp/cpp` - Écran de démarrage
- `MainMenuState.hpp/cpp` - Menu principal
- `PauseState.hpp/cpp` - Menu pause
- `SettingsState.hpp/cpp` - Paramètres
- `TowerMenuState.hpp/cpp` - Sélection de tours

### Controller (Contrôleur)
- `GameManager.hpp/cpp` - Gestion globale du jeu
- `ResourceManager.hpp/cpp` - Gestion des ressources

## 4. Design Patterns ✅

### Pattern Singleton
- **Classes**: `GameManager`, `ResourceManager`
- **Utilité**: Instance unique globale pour la gestion du jeu et des ressources

### Pattern State
- **Interface**: `GameState`
- **Implémentations**: Tous les états du jeu
- **Utilité**: Gestion des différents écrans et transitions

### Pattern Factory
- **Classes**: `ButtonFactory`, `TowerFactory`
- **Utilité**: Création centralisée d'objets boutons et tours

## 5. Fonctionnalités du jeu ✅

### Système de vagues ✅
- Génération automatique d'ennemis
- Difficulté progressive
- Compteur de vagues

### Gestion des ressources ✅
- Système d'or pour acheter des tours
- Gains en éliminant des ennemis
- Affichage en temps réel

### Tours de défense ✅
- Placement interactif sur la carte
- Différents types (Basique, Sniper)
- Portée et dégâts configurables
- Rendu visuel distinct

### Système de vie ✅
- Points de vie des ennemis avec barres de vie
- Vie du joueur (perte quand ennemi atteint la fin)
- Condition de défaite

### Timer et compteurs ✅
- Système de vagues temporisé
- Compteur de score en temps réel
- Affichage des statistiques dans le HUD

### Tableau des scores ✅
- Système de score fonctionnel
- [Extension future: sauvegarde permanente]

## 6. Interface utilisateur ✅

### Menu principal ✅
- Options: Jouer, Paramètres, Scores, Quitter
- Navigation intuitive
- Design soigné

### Paramètres ✅
- Contrôle du volume sonore
- Interface claire
- Sauvegarde des préférences

### Interface de jeu ✅
- HUD informatif (or, vies, vague, score)
- Contrôles intuitifs
- Boutons d'action (pause, menu tours)

## 7. Gestion du son ✅
- Musique d'ambiance en boucle
- Effets sonores (clic, victoire, défaite)
- Contrôle du volume
- Activation/désactivation

## 8. Technologies utilisées ✅
- **Langage**: C++ (standard C++17)
- **Bibliothèque graphique**: SFML 2.5+
- **Outils**: CMake, Make, g++

## 9. Code source ✅
- **Structure**: Code organisé et bien commenté
- **Qualité**: Respect des bonnes pratiques C++
- **Modularité**: Séparation claire des responsabilités
- **Extensibilité**: Architecture permettant l'ajout de fonctionnalités

## 10. Exécutable ✅
- **Génération**: Via CMake ou Makefile
- **Fonctionnalité**: Jeu entièrement jouable
- **Stabilité**: Gestion d'erreurs et cas limites

## Instructions d'utilisation

### Installation et compilation
```bash
# Installation automatique des dépendances et compilation
./setup.sh

# Ou manuellement:
# 1. Installer SFML (voir README.md)
# 2. Compiler:
mkdir build && cd build
cmake .. && make
```

### Exécution
```bash
cd build
./tower-defense
```

### Contrôles
- **Entrée**: Commencer le jeu
- **Clic**: Placer une tour (50 or)
- **Espace**: Lancer nouvelle vague
- **Échap**: Pause
- Navigation par boutons dans les menus

## Fichiers de documentation

1. `README.md` - Documentation complète du projet
2. `docs/UML_Diagrams.md` - Diagrammes UML détaillés
3. `1.instruction.md` - Cahier des charges original
4. `docs/ui_sound.md` - Documentation UI et son

## Scripts utilitaires

1. `setup.sh` - Installation automatique et compilation
2. `verify.sh` - Vérification de l'intégrité du projet
3. `CMakeLists.txt` - Configuration CMake
4. `Makefile` - Configuration Make alternative

## Validation

✅ **Toutes les exigences du cahier des charges sont respectées**
✅ **Architecture MVC implémentée**
✅ **Au moins 2 design patterns utilisés**
✅ **Code source structuré et commenté**
✅ **Exécutable fonctionnel**
✅ **Interface utilisateur complète**
✅ **Gestion audio intégrée**
✅ **Documentation complète**

## Extension possible

Le projet est conçu pour être facilement extensible:
- Nouveaux types d'ennemis et tours
- Niveaux multiples
- Sauvegarde permanente des scores
- Améliorations graphiques
- Multijoueur
