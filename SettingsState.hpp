#ifndef SETTINGSSTATE_HPP
#define SETTINGSSTATE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Game.hpp"

class SettingsState : public GameState {
private:
    sf::Font& font;
    sf::Text paramText;

public:
    SettingsState(sf::Font& fontRef);

    void handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) override;
    void update(sf::RenderWindow&) override;
    void render(sf::RenderWindow& window) override;
};

#endif