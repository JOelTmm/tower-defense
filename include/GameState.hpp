#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleEvent(sf::Event& event, GameManager& game) = 0;
    virtual void update(GameManager& game) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif