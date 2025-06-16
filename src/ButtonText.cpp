<<<<<<< HEAD
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
=======
#include "ButtonText.hpp"

ButtonText::ButtonText(sf::Vector2f size, const std::wstring& buttonText, sf::Font& font) 
    : isHovered(false), isPressed(false) {
    
    // Configuration du rectangle
    shape.setSize(size);
    normalColor = sf::Color(70, 70, 70);
    hoverColor = sf::Color(100, 100, 100);
    clickColor = sf::Color(50, 50, 50);
    shape.setFillColor(normalColor);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color::White);
    
    // Configuration du texte
    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
}

void ButtonText::setPosition(sf::Vector2f pos) {
    shape.setPosition(pos);
    
    // Center text on button
    sf::FloatRect textBounds = text.getLocalBounds();
    sf::FloatRect shapeBounds = shape.getGlobalBounds();
    
    text.setPosition(
        shapeBounds.left + (shapeBounds.width - textBounds.width) / 2,
        shapeBounds.top + (shapeBounds.height - textBounds.height) / 2 - textBounds.top
    );
}

void ButtonText::update(sf::RenderWindow& window) {
    isHovered = isMouseOver(window);
    updateColors();
}

bool ButtonText::isMouseOver(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    return shape.getGlobalBounds().contains(mousePosF);
}

void ButtonText::updateColors() {
    if (isPressed) {
        shape.setFillColor(clickColor);
    } else if (isHovered) {
        shape.setFillColor(hoverColor);
    } else {
        shape.setFillColor(normalColor);
    }
}

bool ButtonText::isClicked(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && 
        event.mouseButton.button == sf::Mouse::Left) {
        if (isMouseOver(window)) {
            isPressed = true;
            return true;
        }
    }
    
    if (event.type == sf::Event::MouseButtonReleased && 
        event.mouseButton.button == sf::Mouse::Left) {
        isPressed = false;
    }
    
>>>>>>> Interface-utilisateur-son
    return false;
}

void ButtonText::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
<<<<<<< HEAD
}
=======
}
>>>>>>> Interface-utilisateur-son
