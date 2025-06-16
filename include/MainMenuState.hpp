#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.hpp"
#include "ResourceManager.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class MainMenuState : public GameState {
private:
    sf::Text titleText;
    sf::Font* font;
    std::vector<std::unique_ptr<Button>> buttons;
    sf::Sprite backgroundSprite;

public:
    MainMenuState();
    void handleEvent(sf::Event& event, GameManager& game) override;
    void update(GameManager& game) override;
    void draw(sf::RenderWindow& window) override;
    
private:
    void setupButtons();
    void handleButtonClick(int buttonIndex, GameManager& game);
};

#endif
