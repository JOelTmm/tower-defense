#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>

class Game; // Déclaration anticipée

class GameState {
public:
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) = 0;
    virtual void update(sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual ~GameState() = default;
};

#endif
