#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <memory>
#include "Tower.hpp"
#include "Enemy.hpp"

class Map {
    int width, height;
    std::vector<std::vector<std::shared_ptr<Tower>>> grid;

public:
    Map(int width, int height);
    bool placeTower(int x, int y, std::shared_ptr<Tower> tower);
    void simulateTurn(std::vector<std::shared_ptr<Enemy>>& enemies);
};

#endif