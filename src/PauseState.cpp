#include "PauseState.hpp"
#include "GameView.hpp"
#include "MainMenuState.hpp"
#include "ButtonFactory.hpp"
#include "Button.hpp"

PauseState::PauseState() {
    // Chargement de la police
    ResourceManager::getInstance().loadFont("assets/arial.TTF", "pause");
    font = &ResourceManager::getInstance().getFont("assets/arial.TTF");
    
    // Overlay semi-transparent
    overlay.setSize(sf::Vector2f(800, 600));
    overlay.setFillColor(sf::Color(0, 0, 0, 128));
    
    // Configuration du titre
    titleText.setFont(*font);
    titleText.setString("PAUSE");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::White);
    
    // Centrer le titre
    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setPosition(400 - titleBounds.width / 2, 150);
    
    // Instructions
    instructionText.setFont(*font);
    instructionText.setString("ESC: Reprendre | Q: Quitter");
    instructionText.setCharacterSize(20);
    instructionText.setFillColor(sf::Color::White);
    
    sf::FloatRect instructionBounds = instructionText.getLocalBounds();
    instructionText.setPosition(400 - instructionBounds.width / 2, 450);
    
    setupButtons();
}

void PauseState::setupButtons() {
    ButtonFactory factory;
    
    // Bouton Reprendre
    auto resumeButton = factory.createTextButton(sf::Vector2f(200, 50), L"REPRENDRE");
    resumeButton->setPosition(sf::Vector2f(300, 250));
    buttons.push_back(std::move(resumeButton));
    
    // Bouton Paramètres
    auto settingsButton = factory.createTextButton(sf::Vector2f(200, 50), L"PARAMETRES");
    settingsButton->setPosition(sf::Vector2f(300, 320));
    buttons.push_back(std::move(settingsButton));
    
    // Bouton Menu principal
    auto menuButton = factory.createTextButton(sf::Vector2f(200, 50), L"MENU PRINCIPAL");
    menuButton->setPosition(sf::Vector2f(300, 390));
    buttons.push_back(std::move(menuButton));
}

void PauseState::handleEvent(sf::Event& event, GameManager& game) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Q) {
            // Retourner au jeu - pour simplifier, on retourne au GameView
            game.changeState(std::make_unique<GameView>());
        }
    }
    
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i]->isClicked(event, game.getWindow())) {
            game.playClick();
            handleButtonClick(i, game);
            break;
        }
    }
}

void PauseState::handleButtonClick(int buttonIndex, GameManager& game) {
    switch (buttonIndex) {
        case 0: // Reprendre
            game.changeState(std::make_unique<GameView>());
            break;
        case 1: // Paramètres
            // TODO: Implémenter l'état des paramètres
            break;
        case 2: // Menu principal
            game.changeState(std::make_unique<MainMenuState>());
            break;
    }
}

void PauseState::update(GameManager& game) {
    for (auto& button : buttons) {
        button->update(game.getWindow());
    }
}

void PauseState::draw(sf::RenderWindow& window) {
    window.draw(overlay);
    window.draw(titleText);
    window.draw(instructionText);
    
    for (auto& button : buttons) {
        button->draw(window);
    }
}