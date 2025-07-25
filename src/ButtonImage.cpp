<<<<<<< HEAD
#include "../include/ButtonImage.hpp"
#include <iostream>

ButtonImage::ButtonImage(const std::string& imagePath, sf::Vector2f size,
                         sf::Color idle, sf::Color hover, sf::Color active)
    : idleColor(idle), hoverColor(hover), activeColor(active), isHovered(false) {
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Erreur chargement image " << imagePath << std::endl;
    }
    sprite.setTexture(texture);

    // Adapter la taille du sprite à size
    sf::Vector2f textureSize(texture.getSize());
    sprite.setScale(size.x / textureSize.x, size.y / textureSize.y);

    shape.setSize(size);
    shape.setFillColor(idleColor);
}

void ButtonImage::setPosition(const sf::Vector2f& pos) {
    shape.setPosition(pos);
    sprite.setPosition(pos);
}

void ButtonImage::update(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    isHovered = shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));

    if (isHovered)
        shape.setFillColor(hoverColor);
    else
        shape.setFillColor(idleColor);
}

bool ButtonImage::isClicked(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            shape.setFillColor(activeColor);
            return true;
        }
    }
=======
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
    
>>>>>>> Interface-utilisateur-son
    return false;
}

void ButtonImage::draw(sf::RenderWindow& window) {
    window.draw(sprite);
<<<<<<< HEAD
    window.draw(shape); // dessiner la forme colorée pour l'effet hover
}
=======
}
>>>>>>> Interface-utilisateur-son
