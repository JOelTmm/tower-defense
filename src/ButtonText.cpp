#include "../include/ButtonText.hpp"

ButtonText::ButtonText(sf::Vector2f size, sf::Font& font, const std::wstring& str,
                       sf::Color idle, sf::Color hover, sf::Color active)
    : idleColor(idle), hoverColor(hover), activeColor(active), isHovered(false) {
    shape.setSize(size);
    shape.setFillColor(idleColor);

    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
}

void ButtonText::setPosition(const sf::Vector2f& pos) {
    shape.setPosition(pos);
    sf::Vector2f shapeSize = shape.getSize();
    text.setPosition(pos.x + shapeSize.x / 2.0f,
                     pos.y + shapeSize.y / 2.0f);
}

void ButtonText::update(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    isHovered = shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));

    if (isHovered)
        shape.setFillColor(hoverColor);
    else
        shape.setFillColor(idleColor);
}

bool ButtonText::isClicked(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            shape.setFillColor(activeColor);
            return true;
        }
    }
    return false;
}

void ButtonText::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}
