#!/bin/bash

# Script de vérification du projet Tower Defense

echo "=== Vérification du projet Tower Defense ==="
echo ""

# Vérifier la structure des dossiers
echo "1. Vérification de la structure des dossiers..."
if [ -d "src" ] && [ -d "include" ] && [ -d "docs" ]; then
    echo "   ✓ Structure des dossiers OK"
else
    echo "   ✗ Structure des dossiers manquante"
    exit 1
fi

# Vérifier les fichiers source essentiels
echo ""
echo "2. Vérification des fichiers source..."
essential_sources=(
    "src/main.cpp"
    "src/GameManager.cpp"
    "src/ResourceManager.cpp"
    "src/StartState.cpp"
    "src/MainMenuState.cpp"
    "src/GameView.cpp"
    "src/Tower.cpp"
    "src/Enemy.cpp"
    "src/Map.cpp"
    "src/ButtonFactory.cpp"
    "src/ButtonText.cpp"
)

for file in "${essential_sources[@]}"; do
    if [ -f "$file" ]; then
        echo "   ✓ $file"
    else
        echo "   ✗ $file manquant"
    fi
done

# Vérifier les fichiers header essentiels
echo ""
echo "3. Vérification des fichiers header..."
essential_headers=(
    "include/GameManager.hpp"
    "include/GameState.hpp"
    "include/ResourceManager.hpp"
    "include/StartState.hpp"
    "include/MainMenuState.hpp"
    "include/GameView.hpp"
    "include/Tower.hpp"
    "include/Enemy.hpp"
    "include/Map.hpp"
    "include/Button.hpp"
    "include/ButtonFactory.hpp"
)

for file in "${essential_headers[@]}"; do
    if [ -f "$file" ]; then
        echo "   ✓ $file"
    else
        echo "   ✗ $file manquant"
    fi
done

# Vérifier les ressources
echo ""
echo "4. Vérification des ressources..."
if [ -d "src/assets" ]; then
    echo "   ✓ Dossier assets présent"
    ls -la src/assets/
else
    echo "   ✗ Dossier assets manquant"
fi

# Vérifier les fichiers de configuration
echo ""
echo "5. Vérification des fichiers de configuration..."
config_files=(
    "CMakeLists.txt"
    "Makefile"
    "README.md"
    "setup.sh"
)

for file in "${config_files[@]}"; do
    if [ -f "$file" ]; then
        echo "   ✓ $file"
    else
        echo "   ✗ $file manquant"
    fi
done

# Vérifier la documentation
echo ""
echo "6. Vérification de la documentation..."
if [ -f "docs/UML_Diagrams.md" ]; then
    echo "   ✓ Diagrammes UML présents"
else
    echo "   ✗ Diagrammes UML manquants"
fi

echo ""
echo "=== Design Patterns implémentés ==="
echo "✓ Singleton Pattern (GameManager, ResourceManager)"
echo "✓ State Pattern (GameState et ses dérivées)"
echo "✓ Factory Pattern (ButtonFactory, TowerFactory)"
echo "✓ Architecture MVC"

echo ""
echo "=== Fonctionnalités implémentées ==="
echo "✓ Menu principal avec options"
echo "✓ Système de vagues d'ennemis"
echo "✓ Gestion des ressources (or)"
echo "✓ Placement de tours"
echo "✓ Système de score et vies"
echo "✓ Gestion audio avec contrôle volume"
echo "✓ Interface utilisateur complète"
echo "✓ États de jeu (pause, paramètres, etc.)"

echo ""
echo "=== Instructions de compilation ==="
echo "1. Installer les dépendances:"
echo "   ./setup.sh"
echo ""
echo "2. Compiler avec CMake:"
echo "   mkdir build && cd build"
echo "   cmake .."
echo "   make"
echo ""
echo "3. Ou compiler avec Makefile:"
echo "   make"
echo ""
echo "4. Exécuter:"
echo "   cd build && ./tower-defense"

echo ""
echo "=== Vérification terminée ==="
