#ifndef BUTTONIMAGE_H
#define BUTTONIMAGE_H

#include "Button.hpp"
#include <SFML/Graphics.hpp>

class ButtonImage : public Button {
private:
    sf::Sprite sprite;
    sf::Texture* texture;
    sf::Color normalColor;
    sf::Color hoverColor;
    sf::Color clickColor;
    bool isHovered;
    bool isPressed;

public:
    ButtonImage(sf::Texture& texture);
    
    void update(sf::RenderWindow& window) override;
    bool isClicked(sf::Event& event, sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    void setPosition(sf::Vector2f pos) override;
    
private:
    bool isMouseOver(sf::RenderWindow& window);
    void updateColors();
};

#endif
