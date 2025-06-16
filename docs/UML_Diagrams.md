# Diagrammes UML - Tower Defense

## Diagramme de cas d'utilisation

```
                Tower Defense - Cas d'utilisation

    Acteur: Joueur
    
    Cas d'utilisation principaux:
    
    1. Démarrer le jeu
       - Accéder au menu principal
       - Sélectionner "Jouer"
       - Initialiser une nouvelle partie
    
    2. Jouer une partie
       - Observer la carte de jeu
       - Placer des tours de défense
       - Gérer les ressources (or)
       - Lancer des vagues d'ennemis
       - Surveiller les points de vie
    
    3. Gérer les tours
       - Sélectionner un type de tour
       - Placer une tour sur la carte
       - [Futur] Améliorer une tour existante
       - [Futur] Vendre une tour
    
    4. Configurer les paramètres
       - Ajuster le volume sonore
       - [Futur] Modifier la difficulté
       - [Futur] Changer la résolution
    
    5. Consulter les scores
       - [Futur] Voir le tableau des scores
       - [Futur] Enregistrer son score
    
    6. Contrôler l'audio
       - Activer/désactiver le son
       - Ajuster le volume
    
    Relations:
    - "Jouer une partie" inclut "Gérer les tours"
    - "Jouer une partie" inclut "Gérer les ressources"
    - "Démarrer le jeu" précède "Jouer une partie"
```

## Diagramme de classes (simplifié)

```
┌─────────────────────┐
│    GameManager      │
│    <<Singleton>>    │
├─────────────────────┤
│ - instance: GM*     │
│ - window: RenderW   │
│ - currentState: GS* │
│ - gold: int         │
│ - lives: int        │
│ - score: int        │
│ - wave: int         │
├─────────────────────┤
│ + getInstance(): GM&│
│ + run(): void       │
│ + changeState(...): │
│ + getGold(): int    │
│ + spendGold(int):   │
│ + loseLife(): void  │
└─────────────────────┘
           │
           │ manages
           ▼
┌─────────────────────┐
│     GameState       │
│    <<abstract>>     │
├─────────────────────┤
│                     │
├─────────────────────┤
│ + handleEvent(...): │
│ + update(...): void │
│ + draw(...): void   │
└─────────────────────┘
           △
           │ inherits
    ┌──────┼──────┐
    │      │      │
┌─────────┐│ ┌──────────┐
│StartSt..││ │MainMenu..│
└─────────┘│ └──────────┘
           │
    ┌──────────┐
    │ GameView │
    └──────────┘
           │
           │ uses
           ▼
┌─────────────────────┐
│        Map          │
├─────────────────────┤
│ - width: int        │
│ - height: int       │
│ - grid: Tower*[]    │
├─────────────────────┤
│ + placeTower(...):  │
│ + render(...): void │
└─────────────────────┘
           │
           │ contains
           ▼
┌─────────────────────┐
│       Tower         │
│    <<abstract>>     │
├─────────────────────┤
│ # level: int        │
│ # price: int        │
│ # attackSpeed: float│
│ # range: float      │
│ # x, y: int         │
├─────────────────────┤
│ + attack(...): void │
│ + render(...): void │
│ + getRange(): float │
└─────────────────────┘
           △
           │
    ┌──────┼──────┐
┌─────────┐  ┌────────────┐
│BasicTow.│  │ SniperTow. │
└─────────┘  └────────────┘

┌─────────────────────┐
│      Enemy          │
├─────────────────────┤
│ - path: pair<int>[] │
│ - currentWaypoint   │
│ - health: int       │
│ - x, y: int         │
├─────────────────────┤
│ + moveTowards(...): │
│ + takeDamage(int):  │
│ + isAlive(): bool   │
│ + render(...): void │
└─────────────────────┘

┌─────────────────────┐
│  ResourceManager    │
│    <<Singleton>>    │
├─────────────────────┤
│ - fonts: Map        │
│ - textures: Map     │
│ - sounds: Map       │
├─────────────────────┤
│ + getFont(...): Font│
│ + loadFont(...): bool│
└─────────────────────┘

┌─────────────────────┐
│   ButtonFactory     │
│    <<Factory>>      │
├─────────────────────┤
│ - font: Font        │
├─────────────────────┤
│ + createTextBtn...  │
└─────────────────────┘
           │ creates
           ▼
┌─────────────────────┐
│      Button         │
│    <<abstract>>     │
├─────────────────────┤
│                     │
├─────────────────────┤
│ + update(...): void │
│ + isClicked(...):   │
│ + draw(...): void   │
│ + setPosition(...): │
└─────────────────────┘
           △
           │
    ┌──────┼──────┐
┌─────────┐  ┌────────────┐
│ButtonTxt│  │ ButtonImg  │
└─────────┘  └────────────┘
```

## Architecture détaillée

### Design Patterns utilisés:

1. **Singleton Pattern**
   - Classes: GameManager, ResourceManager
   - Garantit une seule instance globale

2. **State Pattern**
   - Interface: GameState
   - Implémentations: StartState, MainMenuState, GameView, PauseState, etc.
   - Permet de changer le comportement selon l'état

3. **Factory Pattern**
   - Classes: ButtonFactory, TowerFactory
   - Centralise la création d'objets

4. **Template Method Pattern** (implicite)
   - Dans les classes dérivées de GameState
   - Structure commune avec implémentations spécifiques

### Séparation MVC:

- **Model**: Tower, Enemy, Map (logique métier)
- **View**: States (affichage et interface)
- **Controller**: GameManager (coordination et contrôle)

### Flux de données:

1. main() → GameManager::getInstance()
2. GameManager::run() → boucle principale
3. GameState::handleEvent() → traitement des événements
4. GameState::update() → mise à jour de la logique
5. GameState::draw() → rendu graphique
