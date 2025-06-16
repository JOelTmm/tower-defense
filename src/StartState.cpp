#include "StartState.hpp"
#include "MainMenuState.hpp"
#include "ResourceManager.hpp"

StartState::StartState() {
    // Chargement de la police via le ResourceManager
    ResourceManager::getInstance().loadFont("assets/arial.TTF", "default");
    font = &ResourceManager::getInstance().getFont("assets/arial.TTF");
    
    text.setFont(*font);
    text.setString("Appuyez sur Entree pour commencer");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    
    // Centrer le texte
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(400 - textBounds.width / 2, 250);
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