#include "ButtonFactory.hpp"
#include "ButtonText.hpp"
#include "ResourceManager.hpp"
#include <iostream>

ButtonFactory::ButtonFactory() {
    if (!font.loadFromFile("assets/arial.TTF")) {
        std::cerr << "Erreur lors du chargement de la police dans ButtonFactory" << std::endl;
    }
}

std::unique_ptr<Button> ButtonFactory::createTextButton(sf::Vector2f size, const std::wstring& text) {
    return std::make_unique<ButtonText>(size, text, font);
}