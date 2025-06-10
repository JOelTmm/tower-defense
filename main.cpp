#include "Tower.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::shared_ptr<Tower>> towers;

    auto tower1 = TowerFactory::createTower(TowerType::BASIC);
    auto tower2 = TowerFactory::createTower(TowerType::SNIPER);

    towers.push_back(tower1);
    towers.push_back(tower2);

    for (auto& t : towers) {
        t->attack();
        t->upgrade();
        t->accelerate();
        t->accelerate(); // Test max speed
        t->sell();
    }

    return 0;
}