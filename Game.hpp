#ifndef GAME_HPP
#define GAME_HPP

#include "GameState.hpp"

class Game {
private:
    GameState* currentState;

public:
    Game(GameState* state) : currentState(state) {}

    void changeState(GameState* newState) {
        delete currentState;
        currentState = newState;
    }

    void handleEvent(sf::Event& event, sf::RenderWindow& window) {
        currentState->handleEvent(event, window, *this);
    }

    void update(sf::RenderWindow& window) {
        currentState->update(window);
    }

    void render(sf::RenderWindow& window) {
        currentState->render(window);
    }

    ~Game() {
        delete currentState;
    }
};

#endif
