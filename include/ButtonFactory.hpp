#ifndef BUTTONFACTORY_H
#define BUTTONFACTORY_H

#include <SFML/Graphics.hpp>
#include <memory>

class Button;

class ButtonFactory {
private:
    sf::Font font;

public:
    ButtonFactory();
    std::unique_ptr<Button> createTextButton(sf::Vector2f size, const std::wstring& text);
    sf::Font& getFont() { return font; }
};

#endif