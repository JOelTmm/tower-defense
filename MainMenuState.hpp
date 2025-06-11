#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Game.hpp"
#include "Button.hpp"
#include "SettingsState.hpp" // ← NE PAS inclure ici si SettingsState inclut déjà MainMenuState

class MainMenuState : public GameState {
private:
    sf::Font& font;
    Button settingsButton;

public:
    MainMenuState(sf::Font& fontRef);
    void handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
};

#endif
