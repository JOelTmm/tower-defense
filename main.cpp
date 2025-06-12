#include <iostream>
#include <vector>
#include <memory>

#include "Map.hpp"
#include "Tower.hpp"
#include "Enemy.hpp"

int main() {
    Map gameMap(10, 10);
    std::vector<std::shared_ptr<Enemy>> enemies = {
        std::make_shared<Enemy>(3, 3, 20),
        std::make_shared<Enemy>(6, 6, 15)
    };

    auto tower1 = TowerFactory::createTower(TowerType::BASIC);
    auto tower2 = TowerFactory::createTower(TowerType::SNIPER);

    gameMap.placeTower(2, 2, tower1);
    gameMap.placeTower(5, 5, tower2);

    std::cout << "\n== Tour 1 ==\n";
    gameMap.simulateTurn(enemies);

    std::cout << "\n== Tour 2 ==\n";
    gameMap.simulateTurn(enemies);

    return 0;
}