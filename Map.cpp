#include "Map.hpp"
#include <iostream>
#include <memory>   
#include <vector>
#include <Tower.hpp>
#include <Enemy.hpp>


Map::Map(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<std::shared_ptr<Tower>>(width, nullptr));
}

bool Map::placeTower(int x, int y, std::shared_ptr<Tower> tower) {
    if (x < 0 || y < 0 || x >= width || y >= height) return false;
    if (grid[y][x] != nullptr) return false;
    tower->setPosition(x, y);
    grid[y][x] = tower;
    std::cout << "Tour placée à (" << x << "," << y << ")\n";
    return true;
}

void Map::simulateTurn(std::vector<std::shared_ptr<Enemy>>& enemies) {
    for (const auto& row : grid) {
        for (const auto& tower : row) {
            if (tower != nullptr) {
                tower->attack(enemies);
            }
        }
    }
}
