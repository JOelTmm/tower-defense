#include "../include/MainMenuState.hpp"
#include "../include/SettingsState.hpp"
#include "../include/Game.hpp"

MainMenuState::MainMenuState(ButtonFactory& factory)
    : buttonFactory(factory)
{
    playButton = buttonFactory.createTextButton({200, 50}, L"Jouer");
    settingsButton = buttonFactory.createTextButton({200, 50}, L"Paramètres");

    playButton->setPosition({300, 300});
    settingsButton->setPosition({300, 400});
}

void MainMenuState::handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game)
{
    playButton->update(window);
    settingsButton->update(window);

    if (playButton->isClicked(event, window)) {
        // Ici tu lancerais l'état du jeu par exemple
    }
    if (settingsButton->isClicked(event, window)) {
        game.changeState(std::make_unique<SettingsState>(buttonFactory));
    }
}

void MainMenuState::update(Game& game)
{
    // Animations éventuelles
}

void MainMenuState::draw(sf::RenderWindow& window)
{
    playButton->draw(window);
    settingsButton->draw(window);

    sf::Text title(L"Menu Principal", buttonFactory.getFont(), 50);
    title.setFillColor(sf::Color::White);
    title.setPosition(250, 100);
    window.draw(title);
}
