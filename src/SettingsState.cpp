#include "../include/SettingsState.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/ButtonFactory.hpp"
#include "../include/Game.hpp"

SettingsState::SettingsState(ButtonFactory& factory)
    : buttonFactory(factory)
{
    backButton = buttonFactory.createTextButton({200, 50}, L"Retour");
    backButton->setPosition({300, 500});
}

void SettingsState::handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) {
    backButton->update(window);
    if (backButton->isClicked(event, window)) {
        game.changeState(std::make_unique<MainMenuState>(buttonFactory));
    }
}

void SettingsState::update(Game& game) {
    // animations, etc.
}

void SettingsState::draw(sf::RenderWindow& window) {
    backButton->draw(window);

    sf::Text title(L"Paramètres", buttonFactory.getFont(), 40);
    title.setFillColor(sf::Color::White);
    title.setPosition(300, 100);
    window.draw(title);
}