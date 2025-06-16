#include "ButtonImage.hpp"

ButtonImage::ButtonImage(sf::Texture& buttonTexture) 
    : texture(&buttonTexture), isHovered(false), isPressed(false) {
    
    sprite.setTexture(*texture);
    normalColor = sf::Color::White;
    hoverColor = sf::Color(200, 200, 200);
    clickColor = sf::Color(150, 150, 150);
    sprite.setColor(normalColor);
}

void ButtonImage::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

void ButtonImage::update(sf::RenderWindow& window) {
    isHovered = isMouseOver(window);
    updateColors();
}

bool ButtonImage::isMouseOver(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    return sprite.getGlobalBounds().contains(mousePosF);
}

void ButtonImage::updateColors() {
    if (isPressed) {
        sprite.setColor(clickColor);
    } else if (isHovered) {
        sprite.setColor(hoverColor);
    } else {
        sprite.setColor(normalColor);
    }
}

bool ButtonImage::isClicked(sf::Event& event, sf::RenderWindow& window) {
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
    
    return false;
}

void ButtonImage::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}