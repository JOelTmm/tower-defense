#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "GameState.hpp"
#include <SFML/Graphics.hpp>

class StartState : public GameState {
private:
    sf::Text text;

public:
    StartState();
    void handleEvent(sf::Event& event, GameManager& game) override;
    void update(GameManager& game) override;
    void draw(sf::RenderWindow& window) override;
};

#endif