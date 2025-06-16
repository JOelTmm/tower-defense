# Tower Defense - Documentation Complète

## Vue d'ensemble du projet

Ce projet implémente un jeu de Tower Defense pour PC en utilisant une architecture MVC (Model-View-Controller) avec des design patterns, conformément au cahier des charges fourni.

## Architecture

### Patterns utilisés

1. **Singleton Pattern** - GameManager et ResourceManager
2. **State Pattern** - Gestion des différents états du jeu
3. **Factory Pattern** - ButtonFactory et TowerFactory
4. **Observer Pattern** - (Implémentation future pour les événements)

### Architecture MVC

- **Model** : Enemy, Tower, Map - Logique métier du jeu
- **View** : GameView, StartState, MainMenuState, etc. - Interface utilisateur
- **Controller** : GameManager - Contrôle du flux et coordination

## Structure du projet

```
tower-def/
├── CMakeLists.txt          # Configuration CMake
├── Makefile               # Makefile alternatif
├── setup.sh              # Script d'installation
├── README.md             # Documentation
├── include/              # Fichiers d'en-tête
│   ├── GameManager.hpp
│   ├── GameState.hpp
│   ├── ResourceManager.hpp
│   ├── StartState.hpp
│   ├── MainMenuState.hpp
│   ├── GameView.hpp
│   ├── PauseState.hpp
│   ├── SettingsState.hpp
│   ├── TowerMenuState.hpp
│   ├── Tower.hpp
│   ├── Enemy.hpp
│   ├── Map.hpp
│   ├── Button.hpp
│   ├── ButtonFactory.hpp
│   ├── ButtonText.hpp
│   └── ButtonImage.hpp
├── src/                  # Fichiers sources
│   ├── main.cpp
│   ├── GameManager.cpp
│   ├── ResourceManager.cpp
│   ├── StartState.cpp
│   ├── MainMenuState.cpp
│   ├── GameView.cpp
│   ├── PauseState.cpp
│   ├── SettingsState.cpp
│   ├── TowerMenuState.cpp
│   ├── Tower.cpp
│   ├── Enemy.cpp
│   ├── Map.cpp
│   ├── ButtonFactory.cpp
│   ├── ButtonText.cpp
│   ├── ButtonImage.cpp
│   └── assets/          # Ressources
│       ├── arial.TTF
│       ├── ambiance.wav
│       ├── click.wav
│       ├── victory.wav
│       └── defeat.wav
└── build/               # Dossier de compilation
```

## Fonctionnalités implémentées

### Système de jeu
- ✅ Système de vagues d'ennemis
- ✅ Gestion des ressources (or)
- ✅ Placement et construction de tours
- ✅ Gestion des vies et points de vie des ennemis
- ✅ Système de score
- ✅ Compteur de vagues

### Interface utilisateur
- ✅ Menu principal avec options
- ✅ Gestion du son et volume
- ✅ Interface de jeu avec HUD
- ✅ Menu pause
- ✅ Paramètres
- ✅ Navigation entre les menus

### Audio
- ✅ Musique d'ambiance
- ✅ Effets sonores (clic, victoire, défaite)
- ✅ Contrôle du volume

## Installation et compilation

### Prérequis
- Compilateur C++17 (g++ ou clang++)
- SFML 2.5+ (bibliothèque graphique)
- CMake 3.10+ (optionnel)
- Make

### Installation automatique
```bash
./setup.sh
```

### Installation manuelle

#### Fedora/RHEL/CentOS
```bash
sudo dnf install gcc-c++ make SFML-devel cmake
```

#### Ubuntu/Debian
```bash
sudo apt update
sudo apt install build-essential libsfml-dev cmake
```

#### Compilation
```bash
# Méthode 1: CMake
mkdir build && cd build
cmake ..
make

# Méthode 2: Makefile
make
```

## Utilisation

### Exécution du jeu
```bash
cd build
./tower-defense
```

### Contrôles
- **Entrée** : Commencer (écran de démarrage)
- **Clic gauche** : Placer une tour (coût: 50 or)
- **Espace** : Lancer la prochaine vague
- **Échap** : Pause
- **Q** : Quitter (depuis le menu pause)

### Règles du jeu
1. Les ennemis suivent un chemin prédéfini (ligne centrale)
2. Placez des tours pour les éliminer
3. Gagnez de l'or en éliminant des ennemis
4. Perdez une vie si un ennemi atteint la fin
5. Le jeu se termine quand vous n'avez plus de vies

## Design Patterns détaillés

### 1. Singleton Pattern
**GameManager** et **ResourceManager** utilisent ce pattern pour garantir une instance unique.

```cpp
class GameManager {
private:
    static GameManager* instance;
    GameManager();
public:
    static GameManager& getInstance();
};
```

### 2. State Pattern
Gestion des différents écrans du jeu avec une interface commune.

```cpp
class GameState {
public:
    virtual void handleEvent(sf::Event& event, GameManager& game) = 0;
    virtual void update(GameManager& game) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};
```

### 3. Factory Pattern
Création d'objets (boutons, tours) via des factories.

```cpp
class ButtonFactory {
public:
    std::unique_ptr<Button> createTextButton(sf::Vector2f size, const std::wstring& text);
};

class TowerFactory {
public:
    static std::shared_ptr<Tower> createTower(TowerType type);
};
```

## Extensibilité

Le projet est conçu pour être facilement extensible :

### Ajout de nouveaux types d'ennemis
1. Hériter de la classe `Enemy`
2. Implémenter les méthodes virtuelles
3. Utiliser le factory pattern pour la création

### Ajout de nouveaux types de tours
1. Hériter de la classe `Tower`
2. Implémenter `attack()` et `render()`
3. Ajouter le type dans `TowerType` enum
4. Mettre à jour `TowerFactory`

### Ajout de nouveaux écrans
1. Hériter de `GameState`
2. Implémenter les méthodes virtuelles
3. Gérer les transitions dans `GameManager`

## Améliorations futures

- [ ] Système de sauvegarde des scores
- [ ] Différents types d'ennemis
- [ ] Amélioration des tours
- [ ] Différents niveaux/cartes
- [ ] Animations et effets visuels
- [ ] Système de ressources plus complexe
- [ ] Intelligence artificielle pour les ennemis
- [ ] Multijoueur en réseau

## Problèmes connus

- La gestion des états pourrait être optimisée avec une pile d'états
- Le système de collision pourrait être plus précis
- L'audio pourrait bénéficier d'un système de gestion plus sophistiqué

## Contribution

Pour contribuer au projet :
1. Fork le repository
2. Créer une branche pour votre fonctionnalité
3. Commiter vos changements
4. Créer une pull request

## Licence

Ce projet est développé dans un cadre éducatif.
