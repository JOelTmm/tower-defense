#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "GameState.hpp"
#include "ResourceManager.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class PauseState : public GameState {
private:
    sf::Text titleText;
    sf::Text instructionText;
    sf::Font* font;
    std::vector<std::unique_ptr<Button>> buttons;
    sf::RectangleShape overlay;

public:
    PauseState();
    void handleEvent(sf::Event& event, GameManager& game) override;
    void update(GameManager& game) override;
    void draw(sf::RenderWindow& window) override;
    
private:
    void setupButtons();
    void handleButtonClick(int buttonIndex, GameManager& game);
};

#endif