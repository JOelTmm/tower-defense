#include "StartState.hpp"
#include "MainMenuState.hpp"

StartState::StartState() {
    text.setFont(GameManager::getInstance().getWindow().getDefaultFont());
    text.setString(L"Appuyez sur Entrée pour commencer");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(250, 250);
}

void StartState::handleEvent(sf::Event& event, GameManager& game) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
        game.changeState(std::make_unique<MainMenuState>());
    }
}

void StartState::update(GameManager& game) {}

void StartState::draw(sf::RenderWindow& window) {
    window.draw(text);
}