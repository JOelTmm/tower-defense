#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "GameState.hpp"
#include "ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Button;

class SettingsState : public GameState {
private:
    sf::Text titleText;
    sf::Text volumeText;
    sf::Font* font;
    std::vector<std::unique_ptr<Button>> buttons;
    
public:
    SettingsState();
    void handleEvent(sf::Event& event, GameManager& game) override;
    void update(GameManager& game) override;
    void draw(sf::RenderWindow& window) override;
    
private:
    void setupButtons();
    void handleButtonClick(int buttonIndex, GameManager& game);
    void updateVolumeText(GameManager& game);
};

#endif
