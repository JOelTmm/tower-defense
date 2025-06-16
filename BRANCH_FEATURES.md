# 🎮 Tower Defense - Branche Interface-utilisateur-son

## 🆕 Nouvelles fonctionnalités de cette branche

### 🎨 Interface utilisateur complète
- **StartState** : Écran de démarrage avec animation
- **MainMenuState** : Menu principal avec boutons interactifs
- **GameView** : Interface de jeu avec HUD complet
- **PauseState** : Menu de pause pendant le jeu
- **SettingsState** : Paramètres audio et graphiques
- **TowerMenuState** : Menu de sélection des tours

### 🔊 Système audio intégré
- **Sons d'ambiance** : Musique de fond en boucle
- **Effets sonores** : Sons de clic, victoire, défaite
- **Contrôle du volume** : Réglages dans les paramètres
- **Sons dynamiques** : Effets générés pour les tirs de tours

### 🏗️ Architecture améliorée
- **ResourceManager** : Gestion centralisée des ressources (Singleton)
- **Factory Patterns** : ButtonFactory et TowerFactory pour la création d'objets
- **État du jeu** : Gestion complète des transitions entre états
- **Gestion d'erreurs** : Chargement sécurisé des ressources

## 🚀 Compilation et exécution

### Installation des dépendances

**Linux (Fedora/CentOS) :**
```bash
sudo dnf install gcc-c++ make cmake SFML-devel
```

**Linux (Ubuntu/Debian) :**
```bash
sudo apt install build-essential libsfml-dev cmake
```

### Compilation

```bash
# Méthode 1 : CMake (recommandée)
mkdir build && cd build
cmake ..
make

# Méthode 2 : Makefile
make

# Méthode 3 : Script automatique
chmod +x setup.sh
./setup.sh
```

### Exécution

```bash
cd build
./tower-defense
```

## 🎯 Contrôles du jeu

- **ENTRÉE** : Commencer le jeu (écran de démarrage)
- **ESC** : Pause / Retour au menu
- **CLIC GAUCHE** : Sélectionner boutons/placer tours
- **ESPACE** : Lancer une nouvelle vague d'ennemis

## 📁 Fichiers importants

- **Makefiles** : 3 versions (principal, cross-platform, simple)
- **Documentation** : README.md, LIVRABLES.md, MAKEFILES_GUIDE.md
- **Scripts** : setup.sh (installation), verify.sh (vérification)
- **Assets** : Police arial.TTF, sons WAV d'ambiance

## 🔧 Fonctionnalités techniques

### Patterns implémentés
- ✅ **Singleton** : GameManager, ResourceManager
- ✅ **State** : Tous les états du jeu
- ✅ **Factory** : ButtonFactory, TowerFactory
- ✅ **MVC** : Architecture respectée

### Gestion des ressources
- ✅ **Fonts** : Chargement automatique des polices
- ✅ **Sounds** : Buffers audio partagés
- ✅ **Textures** : Cache des textures (prêt pour extension)
- ✅ **Memory** : Gestion automatique avec smart pointers

## 🧪 Tests et débogage

Un fichier de test SFML simple est inclus :
```bash
g++ -o test_sfml test_sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
./test_sfml
```

## 🎨 Personnalisation

### Ajout de nouveaux sons
1. Placer les fichiers WAV dans `src/assets/`
2. Ajouter le chargement dans `GameManager.cpp`
3. Utiliser via `ResourceManager::getInstance().getSoundBuffer()`

### Ajout de nouveaux états
1. Hériter de `GameState`
2. Implémenter `handleEvent()`, `update()`, `draw()`
3. Ajouter la transition dans les autres états

## 📊 État du projet

- ✅ **Compilation** : Fonctionnelle sur Linux/Windows
- ✅ **Architecture** : MVC + Patterns respectés
- ✅ **Interface** : Complète et interactive
- ✅ **Audio** : Système complet implémenté
- ✅ **Documentation** : Complète et détaillée
- ✅ **Tests** : Compilation et exécution validées

## 🔄 Prochaines améliorations possibles

- [ ] Sauvegarde des scores
- [ ] Multiples niveaux
- [ ] Animations des tours et ennemis
- [ ] Système de particules
- [ ] Menu des achievements
- [ ] Support des textures/sprites

---

**Le projet est maintenant entièrement fonctionnel et prêt pour le déploiement ! 🎉**
