#include "MainMenuState.hpp"
#include "GameView.hpp"
#include "SettingsState.hpp"
#include "PauseState.hpp"
#include "ButtonFactory.hpp"
#include "Button.hpp"
#include <iostream>

MainMenuState::MainMenuState() {
    // Chargement de la police
    ResourceManager::getInstance().loadFont("assets/arial.TTF", "menu");
    font = &ResourceManager::getInstance().getFont("assets/arial.TTF");
    
    // Configuration du titre
    titleText.setFont(*font);
    titleText.setString("TOWER DEFENSE");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::White);
    
    // Centrer le titre
    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setPosition(400 - titleBounds.width / 2, 100);
    
    setupButtons();
}

void MainMenuState::setupButtons() {
    ButtonFactory factory;
    
    // Bouton Jouer
    auto playButton = factory.createTextButton(sf::Vector2f(200, 50), L"JOUER");
    playButton->setPosition(sf::Vector2f(300, 250));
    buttons.push_back(std::move(playButton));
    
    // Bouton Paramètres
    auto settingsButton = factory.createTextButton(sf::Vector2f(200, 50), L"PARAMETRES");
    settingsButton->setPosition(sf::Vector2f(300, 320));
    buttons.push_back(std::move(settingsButton));
    
    // Bouton Scores
    auto scoresButton = factory.createTextButton(sf::Vector2f(200, 50), L"SCORES");
    scoresButton->setPosition(sf::Vector2f(300, 390));
    buttons.push_back(std::move(scoresButton));
    
    // Bouton Quitter
    auto quitButton = factory.createTextButton(sf::Vector2f(200, 50), L"QUITTER");
    quitButton->setPosition(sf::Vector2f(300, 460));
    buttons.push_back(std::move(quitButton));
}

void MainMenuState::handleEvent(sf::Event& event, GameManager& game) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i]->isClicked(event, game.getWindow())) {
            game.playClick();
            handleButtonClick(i, game);
            break;
        }
    }
}

void MainMenuState::handleButtonClick(int buttonIndex, GameManager& game) {
    switch (buttonIndex) {
        case 0: // Jouer
            game.changeState(std::make_unique<GameView>());
            break;
        case 1: // Paramètres
            game.changeState(std::make_unique<SettingsState>());
            break;
        case 2: // Scores
            // TODO: Implémenter l'état des scores
            std::cout << "Scores sélectionnés" << std::endl;
            break;
        case 3: // Quitter
            game.getWindow().close();
            break;
    }
}

void MainMenuState::update(GameManager& game) {
    for (auto& button : buttons) {
        button->update(game.getWindow());
    }
}

void MainMenuState::draw(sf::RenderWindow& window) {
    window.draw(titleText);
    for (auto& button : buttons) {
        button->draw(window);
    }
}