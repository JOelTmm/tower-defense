#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
public:
    virtual ~Button() = default;

    virtual void setPosition(const sf::Vector2f& pos) = 0;
    virtual void update(const sf::RenderWindow& window) = 0;
    virtual bool isClicked(const sf::Event& event, const sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif // BUTTON_HPP
