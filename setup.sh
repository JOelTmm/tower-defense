#!/bin/bash

# Script de setup pour le projet Tower Defense

echo "=== Setup du projet Tower Defense ==="

# Détecter la distribution
if command -v dnf &> /dev/null; then
    echo "Système détecté: Fedora/RHEL/CentOS"
    echo "Installation des dépendances..."
    sudo dnf install -y gcc-c++ make SFML-devel cmake
elif command -v apt &> /dev/null; then
    echo "Système détecté: Ubuntu/Debian"
    echo "Installation des dépendances..."
    sudo apt update && sudo apt install -y build-essential libsfml-dev cmake
elif command -v pacman &> /dev/null; then
    echo "Système détecté: Arch Linux"
    echo "Installation des dépendances..."
    sudo pacman -S gcc make sfml cmake
else
    echo "Distribution non supportée automatiquement."
    echo "Veuillez installer manuellement: g++, make, SFML, cmake"
    exit 1
fi

echo "=== Compilation du projet ==="

# Créer le dossier de build
mkdir -p build
cd build

# Utiliser cmake si disponible, sinon utiliser make
if command -v cmake &> /dev/null; then
    echo "Compilation avec CMake..."
    cmake ..
    make
else
    echo "Compilation avec Makefile..."
    cd ..
    make
fi

echo "=== Setup terminé ==="
echo "Exécutable disponible dans: build/tower-defense"
echo ""
echo "Pour exécuter le jeu:"
echo "  cd build && ./tower-defense"
echo ""
echo "Commandes disponibles:"
echo "  make            - Compiler le projet"
echo "  make clean      - Nettoyer les fichiers de build"
echo "  make debug      - Afficher les informations de debug"
