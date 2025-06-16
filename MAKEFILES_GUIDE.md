# Makefiles pour Tower Defense - Guide d'utilisation

Ce projet contient plusieurs Makefiles pour différents besoins :

## 1. Makefile principal (Makefile)
Le Makefile principal du projet Tower Defense, spécialement conçu pour la structure actuelle.

### Utilisation :
```bash
# Compilation normale
make

# Compilation debug
make debug

# Compilation release
make release

# Nettoyer
make clean

# Compiler et exécuter
make run
```

## 2. Makefile cross-platform (Makefile.cross-platform)
Makefile avancé compatible Linux et Windows avec détection automatique de l'OS.

### Utilisation :
```bash
# Utiliser le Makefile cross-platform
make -f Makefile.cross-platform

# Configuration Windows statique
make -f Makefile.cross-platform windows-static

# Configuration Windows avec DLL
make -f Makefile.cross-platform windows-shared

# Configuration Linux optimisée
make -f Makefile.cross-platform linux

# Afficher l'aide
make -f Makefile.cross-platform help
```

## 3. Makefile simple (Makefile.simple)
Makefile générique pour projets simples avec main.cpp et game.cpp.

### Utilisation :
```bash
# Utiliser le Makefile simple
make -f Makefile.simple

# Afficher les instructions d'installation des dépendances
make -f Makefile.simple install-deps

# Vérifier les dépendances
make -f Makefile.simple check

# Afficher l'aide
make -f Makefile.simple help
```

## Installation des dépendances

### Linux (Fedora/CentOS/RHEL) :
```bash
sudo dnf install gcc-c++ make cmake SFML-devel
```

### Linux (Ubuntu/Debian) :
```bash
sudo apt update
sudo apt install build-essential libsfml-dev cmake
```

### Linux (Arch) :
```bash
sudo pacman -S base-devel sfml cmake
```

### Windows :
1. Téléchargez SFML depuis https://www.sfml-dev.org/download.php
2. Choisissez la version MinGW correspondant à votre compilateur
3. Extraire dans un dossier 'SFML' à la racine du projet
4. Structure attendue :
   ```
   SFML/
   ├── include/
   ├── lib/
   └── bin/ (pour les DLL)
   ```

## Compilation Windows

### Compilation statique (recommandée) :
```bash
g++ -o tower_defense.exe main.cpp game.cpp -static -ISFML/include -LSFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg
```

### Compilation dynamique :
```bash
g++ -o tower_defense.exe main.cpp game.cpp -ISFML/include -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
```

**Note :** Pour la version dynamique, copiez les DLL SFML dans le même répertoire que l'exécutable :
- sfml-graphics-2.dll
- sfml-window-2.dll
- sfml-audio-2.dll
- sfml-system-2.dll

## État actuel du projet

✅ **RÉUSSI** :
- Dépendances SFML installées (version 2.6.2)
- Compilation réussie sur Fedora Linux
- Exécutable créé : `build/tower-defense`
- Assets copiés dans le dossier de build
- Tous les fichiers sources compilent sans erreur

⚠️ **Warnings mineurs** :
- Comparaisons signed/unsigned dans Enemy.hpp (non critiques)
- Paramètres non utilisés dans certaines fonctions (normal pour l'implémentation actuelle)

## Test du jeu

Pour tester le jeu compilé :
```bash
cd /home/noa/tower-def
make run
```

Ou directement :
```bash
cd /home/noa/tower-def/build
./tower-defense
```

## Structure du projet

```
tower-def/
├── Makefile                    # Makefile principal
├── Makefile.cross-platform     # Makefile cross-platform avancé
├── Makefile.simple            # Makefile générique simple
├── CMakeLists.txt             # Configuration CMake
├── src/                       # Code source
├── include/                   # Headers
├── build/                     # Dossier de compilation
│   ├── tower-defense         # Exécutable
│   └── assets/               # Ressources du jeu
└── docs/                     # Documentation
```

## Conseils pour le développement

1. **Utilisez le Makefile principal** pour le développement quotidien
2. **Utilisez le Makefile cross-platform** pour des builds sur différents OS
3. **Utilisez le Makefile simple** comme base pour de nouveaux projets
4. **Toujours tester avec `make run`** après les modifications
5. **Utiliser `make clean`** avant les builds finaux

Le projet est maintenant entièrement fonctionnel et prêt pour le développement et les tests !
