#include "TowerMenuState.hpp"
#include "GameView.hpp"
#include "ButtonFactory.hpp"
#include "Button.hpp"

TowerMenuState::TowerMenuState() {
    // Chargement de la police
    ResourceManager::getInstance().loadFont("assets/arial.TTF", "towermenu");
    font = &ResourceManager::getInstance().getFont("assets/arial.TTF");
    
    // Overlay semi-transparent
    overlay.setSize(sf::Vector2f(800, 600));
    overlay.setFillColor(sf::Color(0, 0, 0, 128));
    
    // Configuration du titre
    titleText.setFont(*font);
    titleText.setString("MENU DES TOURS");
    titleText.setCharacterSize(40);
    titleText.setFillColor(sf::Color::White);
    
    // Centrer le titre
    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setPosition(400 - titleBounds.width / 2, 150);
    
    // Instructions
    instructionText.setFont(*font);
    instructionText.setString("Choisissez le type de tour a placer");
    instructionText.setCharacterSize(20);
    instructionText.setFillColor(sf::Color::White);
    
    sf::FloatRect instructionBounds = instructionText.getLocalBounds();
    instructionText.setPosition(400 - instructionBounds.width / 2, 200);
    
    setupButtons();
}

void TowerMenuState::setupButtons() {
    ButtonFactory factory;
    
    // Bouton Tour Basique
    auto basicTowerButton = factory.createTextButton(sf::Vector2f(250, 50), L"TOUR BASIQUE (50 or)");
    basicTowerButton->setPosition(sf::Vector2f(275, 280));
    buttons.push_back(std::move(basicTowerButton));
    
    // Bouton Tour Sniper
    auto sniperTowerButton = factory.createTextButton(sf::Vector2f(250, 50), L"TOUR SNIPER (100 or)");
    sniperTowerButton->setPosition(sf::Vector2f(275, 350));
    buttons.push_back(std::move(sniperTowerButton));
    
    // Bouton Retour
    auto backButton = factory.createTextButton(sf::Vector2f(150, 50), L"RETOUR");
    backButton->setPosition(sf::Vector2f(325, 420));
    buttons.push_back(std::move(backButton));
}

void TowerMenuState::handleEvent(sf::Event& event, GameManager& game) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        game.changeState(std::make_unique<GameView>());
    }
    
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i]->isClicked(event, game.getWindow())) {
            game.playClick();
            handleButtonClick(i, game);
            break;
        }
    }
}

void TowerMenuState::handleButtonClick(int buttonIndex, GameManager& game) {
    switch (buttonIndex) {
        case 0: // Tour Basique
            if (game.getGold() >= 50) {
                // Retourner au jeu pour placer la tour
                // Dans une version plus complète, on pourrait stocker le type de tour sélectionné
                game.changeState(std::make_unique<GameView>());
            }
            break;
        case 1: // Tour Sniper
            if (game.getGold() >= 100) {
                // Retourner au jeu pour placer la tour
                game.changeState(std::make_unique<GameView>());
            }
            break;
        case 2: // Retour
            game.changeState(std::make_unique<GameView>());
            break;
    }
}

void TowerMenuState::update(GameManager& game) {
    for (auto& button : buttons) {
        button->update(game.getWindow());
    }
}

void TowerMenuState::draw(sf::RenderWindow& window) {
    window.draw(overlay);
    window.draw(titleText);
    window.draw(instructionText);
    
    for (auto& button : buttons) {
        button->draw(window);
    }
}