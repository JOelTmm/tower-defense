#include "SettingsState.hpp"
#include "MainMenuState.hpp"  // ✅ inclure ici seulement

SettingsState::SettingsState(sf::Font& fontRef) : font(fontRef) {
    paramText.setFont(font);
    paramText.setString(L"Écran Paramètres\n(Cliquez pour revenir)");
    paramText.setCharacterSize(28);
    paramText.setFillColor(sf::Color::White);
    paramText.setPosition(200, 250);
}

void SettingsState::handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) {
    if (event.type == sf::Event::MouseButtonPressed) {
        game.changeState(new MainMenuState(font));  // ✅ ici MainMenuState est visible
    }
}

void SettingsState::update(sf::RenderWindow&) {}

void SettingsState::render(sf::RenderWindow& window) {
    window.clear(sf::Color(50, 50, 50));
    window.draw(paramText);
    window.display();
}
