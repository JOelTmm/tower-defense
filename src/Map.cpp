#include "Map.hpp"
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
        }
    }
}

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
            }
        }
    }
}