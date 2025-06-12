#include "../include/Game.hpp"
#include "../include/MainMenuState.hpp"

Game::Game(ButtonFactory& factory)
    : window(sf::VideoMode(800, 600), "Tower Defense"),
      buttonFactory(factory)
{
    changeState(std::make_unique<MainMenuState>(buttonFactory));
}


void Game::run()
{
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (currentState)
                currentState->handleEvent(event, window, *this);
        }

        if (currentState)
            currentState->update(*this);

        window.clear();
        if (currentState)
            currentState->draw(window);
        window.display();
    }
}

void Game::changeState(std::unique_ptr<GameState> newState)
{
    currentState = std::move(newState);
}
