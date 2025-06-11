// MainMenuState.cpp
#include "MainMenuState.hpp"
#include "SettingsState.hpp"

MainMenuState::MainMenuState(sf::Font& fontRef)
    : font(fontRef),
      settingsButton({200, 50}, font, L"Paramètres",
                     sf::Color(70,130,180), sf::Color(100,149,237), sf::Color(65,105,225))
{
    settingsButton.setPosition({300, 400});
}

void MainMenuState::handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) {
    if (settingsButton.isClicked(event, window)) {
        game.changeState(new SettingsState(font));
    }
}

void MainMenuState::update(sf::RenderWindow& window) {
    settingsButton.update(window);
}

void MainMenuState::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    settingsButton.draw(window);
    window.display();
}
