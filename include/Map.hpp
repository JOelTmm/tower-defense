#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Tower.hpp"
#include "Enemy.hpp"
#include "GameManager.hpp"

class Map {
private:
    int width, height;
    std::vector<std::shared_ptr<Tower>> grid;

public:
    Map(int width, int height);
    bool placeTower(int x, int y, std::shared_ptr<Tower> tower);
    void simulateTurn(std::vector<std::shared_ptr<Enemy>>& enemies, GameManager& game);
    void render(sf::RenderWindow& window);
};

#endif