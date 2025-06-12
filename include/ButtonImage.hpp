#ifndef BUTTONIMAGE_HPP
#define BUTTONIMAGE_HPP

#include "Button.hpp"

class ButtonImage : public Button {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RectangleShape shape; // pour détection clic et hover
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    bool isHovered = false;

public:
    // imagePath est le chemin vers l'image à charger
    ButtonImage(const std::string& imagePath, sf::Vector2f size,
                sf::Color idle, sf::Color hover, sf::Color active);

    void setPosition(const sf::Vector2f& pos) override;
    void update(const sf::RenderWindow& window) override;
    bool isClicked(const sf::Event& event, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
};

#endif // BUTTONIMAGE_HPP
