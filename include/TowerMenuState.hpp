#ifndef TOWERMENUSTATE_H
#define TOWERMENUSTATE_H

#include "GameState.hpp"
#include "ResourceManager.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class TowerMenuState : public GameState {
private:
    sf::Text titleText;
    sf::Text instructionText;
    sf::Font* font;
    std::vector<std::unique_ptr<Button>> buttons;
    sf::RectangleShape overlay;

public:
    TowerMenuState();
    void handleEvent(sf::Event& event, GameManager& game) override;
    void update(GameManager& game) override;
    void draw(sf::RenderWindow& window) override;
    
private:
    void setupButtons();
    void handleButtonClick(int buttonIndex, GameManager& game);
};

#endif