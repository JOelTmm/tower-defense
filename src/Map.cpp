#include "Map.hpp"

Map::Map() {
    // Configuration des formes pour le dessin
    emptyTile.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    emptyTile.setFillColor(sf::Color(50, 150, 50)); // Vert foncé

    pathTile.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    pathTile.setFillColor(sf::Color(210, 180, 140)); // Beige (couleur sable)

    startTile.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    startTile.setFillColor(sf::Color(255, 100, 100)); // Rouge pour le départ

    endTile.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    endTile.setFillColor(sf::Color(100, 100, 255)); // Bleu pour l'arrivée

    // Création de la carte et du chemin
    createSimplePath();
    generateWaypoints();
}

void Map::createSimplePath() {
    // 1. Initialise la grille avec des tuiles vides
    grid.assign(MAP_HEIGHT, std::vector<TileType>(MAP_WIDTH, TileType::EMPTY));

    // 2. Crée un chemin horizontal simple au milieu de la carte
    int pathRow = MAP_HEIGHT / 2;
    for (int col = 1; col < MAP_WIDTH - 1; ++col) {
        grid[pathRow][col] = TileType::PATH;
    }

    // 3. Place les bases de départ et d'arrivée
    grid[pathRow][0] = TileType::START_BASE; // Base de départ à gauche
    grid[pathRow][MAP_WIDTH - 1] = TileType::END_BASE;   // Base d'arrivée à droite
}

void Map::generateWaypoints() {
    pathWaypoints.clear();
    int pathRow = MAP_HEIGHT / 2;

    // Ajoute les points de passage (waypoints) en coordonnées pixels
    // Le centre de chaque tuile du chemin.
    for (int col = 0; col < MAP_WIDTH; ++col) {
        if (grid[pathRow][col] == TileType::START_BASE || grid[pathRow][col] == TileType::PATH || grid[pathRow][col] == TileType::END_BASE) {
            pathWaypoints.push_back(sf::Vector2f(
                col * TILE_SIZE + TILE_SIZE / 2.0f,
                pathRow * TILE_SIZE + TILE_SIZE / 2.0f
            ));
        }
    }
}

const std::vector<sf::Vector2f>& Map::getPathWaypoints() const {
    return pathWaypoints;
}

void Map::draw(sf::RenderWindow& window) {
    for (int row = 0; row < MAP_HEIGHT; ++row) {
        for (int col = 0; col < MAP_WIDTH; ++col) {
            sf::RectangleShape* currentTile = nullptr;

            switch (grid[row][col]) {
                case TileType::EMPTY:
                    currentTile = &emptyTile;
                    break;
                case TileType::PATH:
                    currentTile = &pathTile;
                    break;
                case TileType::START_BASE:
                    currentTile = &startTile;
                    break;
                case TileType::END_BASE:
                    currentTile = &endTile;
                    break;
            }

            if (currentTile) {
                currentTile->setPosition(col * TILE_SIZE, row * TILE_SIZE);
                window.draw(*currentTile);
            }
        }
    }
}