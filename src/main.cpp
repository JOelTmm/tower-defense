#include <SFML/Graphics.hpp>
#include "../include/Game.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/ButtonFactory.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense");
    ButtonFactory buttonFactory;
    Game game(buttonFactory);

    game.run();

    return 0;
}
