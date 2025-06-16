#include "Map.hpp"
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
    grid.resize(width * height, nullptr);
}

bool Map::placeTower(int x, int y, std::shared_ptr<Tower> tower) {
    if (x >= 0 && x < width && y >= 0 && y < height && !grid[y * width + x]) {
        grid[y * width + x] = tower;
        return true;
    }
    return false;
}

void Map::simulateTurn(std::vector<std::shared_ptr<Enemy>>& enemies, GameManager& game) {
    for (auto it = enemies.begin(); it != enemies.end();) {
        auto& enemy = *it;
        if (!enemy->isAlive()) {
            it = enemies.erase(it);
            continue;
        }

        if (enemy->hasReachedEnd()) {
            std::cout << "Ennemi atteint la sortie à (" << enemy->getX() / 50 << "," << enemy->getY() / 50 << ")\n";
            game.loseLife(); // Réduire les vies via GameManager
            it = enemies.erase(it);
        } else {
            int targetX = (enemy->getX() / 50 + 1) * 50; // Avancer vers la droite
            int targetY = enemy->getY();
            if (targetX >= width * 50) {
                targetX = enemy->getX();
                targetY = (enemy->getY() / 50 + 1) * 50; // Descendre si fin de ligne
            }
            enemy->moveTowards(targetX, targetY);

            // Attaque des tours
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    if (auto tower = grid[y * width + x]) {
                        int dx = enemy->getX() - (x * 50 + 25);
                        int dy = enemy->getY() - (y * 50 + 25);
                        if (dx * dx + dy * dy <= 10000) { // Portée de 100 pixels
                            enemy->takeDamage(1);
                        }
                    }
                }
            }
            ++it;
        }
    }
}

void Map::render(sf::RenderWindow& window) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            sf::RectangleShape cell(sf::Vector2f(50, 50));
            cell.setPosition(x * 50, y * 50);
            cell.setFillColor((x + y) % 2 == 0 ? sf::Color(0, 100, 0) : sf::Color(0, 150, 0));
            window.draw(cell);
            if (auto tower = grid[y * width + x]) {
                // Rendu de la tour (à implémenter)
            }
        }
    }
}