# Makefile pour Tower Defense

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Dossiers
SRCDIR = src
INCDIR = include
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj

# Sources
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Executable
TARGET = $(BUILDDIR)/tower-defense

# Règle principale
all: directories $(TARGET)

# Créer les dossiers nécessaires
directories:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(OBJDIR)

# Règle pour l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

# Règle pour les fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BUILDDIR)

# Installation des dépendances (pour Fedora/DNF)
install-deps:
	sudo dnf install -y gcc-c++ make SFML-devel

# Installation des dépendances (pour Ubuntu/APT)
install-deps-ubuntu:
	sudo apt update && sudo apt install -y build-essential libsfml-dev

# Règles phony
.PHONY: all clean directories install-deps install-deps-ubuntu

# Affichage des variables pour débogage
debug:
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Target: $(TARGET)"
