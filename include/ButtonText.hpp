#ifndef BUTTONTEXT_H
#define BUTTONTEXT_H

#include "Button.hpp"
#include <SFML/Graphics.hpp>

class ButtonText : public Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color normalColor;
    sf::Color hoverColor;
    sf::Color clickColor;
    bool isHovered;
    bool isPressed;

public:
    ButtonText(sf::Vector2f size, const std::wstring& buttonText, sf::Font& font);
    
    void update(sf::RenderWindow& window) override;
    bool isClicked(sf::Event& event, sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    void setPosition(sf::Vector2f pos) override;
    
private:
    bool isMouseOver(sf::RenderWindow& window);
    void updateColors();
};

#endif
