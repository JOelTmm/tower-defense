#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>

class Game; // forward declaration

class GameState {
public:
    virtual ~GameState() = default;

    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) = 0;
    virtual void update(Game& game) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif
