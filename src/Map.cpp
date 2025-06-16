#include "Map.hpp"
<<<<<<< HEAD

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
=======
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
    grid.resize(width * height, nullptr);
}

bool Map::placeTower(int x, int y, std::shared_ptr<Tower> tower) {
    if (x >= 0 && x < width && y >= 0 && y < height && !grid[y * width + x]) {
        grid[y * width + x] = tower;
        tower->setPosition(x * 50 + 25, y * 50 + 25 + 80); // +80 pour le décalage du HUD
        return true;
    }
    return false;
}

void Map::simulateTurn(std::vector<std::shared_ptr<Enemy>>& enemies, GameManager& game) {
    // Cette méthode peut être appelée par GameView pour la simulation
    for (auto it = enemies.begin(); it != enemies.end();) {
        auto& enemy = *it;
        if (!enemy->isAlive()) {
            game.addGold(10);
            game.addScore(100);
            it = enemies.erase(it);
            continue;
        }

        if (enemy->hasReachedEnd()) {
            std::cout << "Ennemi atteint la sortie!\n";
            game.loseLife();
            it = enemies.erase(it);
        } else {
            // Logique de déplacement des ennemis déplacée vers GameView
            ++it;
        }
    }
    
    // Attaque des tours
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (auto tower = grid[y * width + x]) {
                // Convertir en vecteur pour compatibilité
                std::vector<std::shared_ptr<Enemy>> enemySharedPtrs;
                for (auto& enemy : enemies) {
                    enemySharedPtrs.push_back(std::shared_ptr<Enemy>(enemy.get(), [](Enemy*){})); // shared_ptr sans destruction
                }
                tower->attack(enemySharedPtrs);
            }
>>>>>>> Interface-utilisateur-son
        }
    }
}

<<<<<<< HEAD
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
=======
void Map::render(sf::RenderWindow& window) {
    // Dessiner la grille de jeu (décalée de 80 pixels vers le bas pour le HUD)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            sf::RectangleShape cell(sf::Vector2f(50, 50));
            cell.setPosition(x * 50, y * 50 + 80);
            
            // Chemin des ennemis (ligne du milieu)
            if (y == 6) {
                cell.setFillColor(sf::Color(139, 69, 19)); // Marron pour le chemin
            } else {
                cell.setFillColor((x + y) % 2 == 0 ? sf::Color(0, 100, 0) : sf::Color(0, 120, 0)); // Vert pour l'herbe
            }
            
            // Contour de la cellule
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color(0, 0, 0, 50));
            
            window.draw(cell);
            
            // Dessiner la tour si elle existe
            if (auto tower = grid[y * width + x]) {
                tower->render(window);
>>>>>>> Interface-utilisateur-son
            }
        }
    }
}