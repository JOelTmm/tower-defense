#ifndef BUTTONTEXT_HPP
#define BUTTONTEXT_HPP

#include "Button.hpp"

class ButtonText : public Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    bool isHovered = false;

public:
    ButtonText(sf::Vector2f size, sf::Font& font, const std::wstring& str,
               sf::Color idle, sf::Color hover, sf::Color active);

    void setPosition(const sf::Vector2f& pos) override;
    void update(const sf::RenderWindow& window) override;
    bool isClicked(const sf::Event& event, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
};

#endif // BUTTONTEXT_HPP
