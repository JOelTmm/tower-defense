#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include "GameState.hpp"
#include "ButtonFactory.hpp"

class Game {
private:
    sf::RenderWindow window;
    std::unique_ptr<GameState> currentState;
    ButtonFactory buttonFactory;

public:
    Game(ButtonFactory& buttonFactory);
    void run();
    void changeState(std::unique_ptr<GameState> newState);

    sf::RenderWindow& getWindow() { return window; }
    ButtonFactory& getButtonFactory() { return buttonFactory; }
};

#endif
