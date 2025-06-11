#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "MainMenuState.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu avec State Pattern");

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Erreur chargement police\n";
        return 1;
    }

    Game game(new MainMenuState(font));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            game.handleEvent(event, window);
        }

        game.update(window);
        game.render(window);
    }

    return 0;
}
