// ButtonFactory.hpp
#ifndef BUTTONFACTORY_HPP
#define BUTTONFACTORY_HPP

#include <memory>
#include "ButtonText.hpp"
#include "ButtonImage.hpp"

class ButtonFactory {
private:
    sf::Font font;

public:
    ButtonFactory() {
        if (!font.loadFromFile("assets/arial.ttf")) {
            // Gérer l'erreur (throw ou message)
        }
    }

    std::unique_ptr<ButtonText> createTextButton(sf::Vector2f size, const std::wstring& label) {
        // La font est interne, pas besoin de la passer ici
        return std::make_unique<ButtonText>(size, font, label,
                                            sf::Color(70,130,180),    // idle
                                            sf::Color(100,149,237),   // hover
                                            sf::Color(65,105,225));   // active
    }
    
    const sf::Font& getFont() const {
        return font;
    }

    // Exemple pour ImageButton, à adapter
    std::unique_ptr<ButtonImage> createImageButton(sf::Vector2f size, const sf::Texture& texture) {
        return std::make_unique<ButtonImage>("path/to/image.png", size, sf::Color::White, sf::Color::Yellow, sf::Color::Red);

    }
};

#endif
