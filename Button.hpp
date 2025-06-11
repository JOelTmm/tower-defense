#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    bool isHovered = false;

public:
    Button(sf::Vector2f size, sf::Font& font, const std::wstring& str,
           sf::Color idle, sf::Color hover, sf::Color active) {
        shape.setSize(size);
        idleColor = idle;
        hoverColor = hover;
        activeColor = active;
        shape.setFillColor(idleColor);

        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        // Centrer le texte dans le bouton
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
    }

    void setPosition(sf::Vector2f pos) {
        shape.setPosition(pos);
        // Positionner le texte au centre du bouton
        sf::Vector2f shapeSize = shape.getSize();
        text.setPosition(pos.x + shapeSize.x / 2.0f,
                         pos.y + shapeSize.y / 2.0f);
    }

    void update(const sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        isHovered = shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));

        if (isHovered)
            shape.setFillColor(hoverColor);
        else
            shape.setFillColor(idleColor);
    }

    bool isClicked(const sf::Event& event, const sf::RenderWindow& window) {
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

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};

#endif // BUTTON_HPP
