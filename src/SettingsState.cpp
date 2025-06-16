#include "SettingsState.hpp"
#include "MainMenuState.hpp"
#include "ButtonFactory.hpp"
#include "Button.hpp"
#include <sstream>

SettingsState::SettingsState() {
    // Chargement de la police
    ResourceManager::getInstance().loadFont("assets/arial.TTF", "settings");
    font = &ResourceManager::getInstance().getFont("assets/arial.TTF");
    
    // Configuration du titre
    titleText.setFont(*font);
    titleText.setString("PARAMETRES");
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::White);
    
    // Centrer le titre
    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setPosition(400 - titleBounds.width / 2, 100);
    
    // Configuration du texte de volume
    volumeText.setFont(*font);
    volumeText.setCharacterSize(24);
    volumeText.setFillColor(sf::Color::White);
    volumeText.setPosition(200, 250);
    
    setupButtons();
}

void SettingsState::setupButtons() {
    ButtonFactory factory;
    
    // Bouton Volume -
    auto volumeDownButton = factory.createTextButton(sf::Vector2f(60, 40), L"VOLUME -");
    volumeDownButton->setPosition(sf::Vector2f(300, 300));
    buttons.push_back(std::move(volumeDownButton));
    
    // Bouton Volume +
    auto volumeUpButton = factory.createTextButton(sf::Vector2f(60, 40), L"VOLUME +");
    volumeUpButton->setPosition(sf::Vector2f(400, 300));
    buttons.push_back(std::move(volumeUpButton));
    
    // Bouton Retour
    auto backButton = factory.createTextButton(sf::Vector2f(150, 50), L"RETOUR");
    backButton->setPosition(sf::Vector2f(325, 450));
    buttons.push_back(std::move(backButton));
}

void SettingsState::handleEvent(sf::Event& event, GameManager& game) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        game.changeState(std::make_unique<MainMenuState>());
    }
    
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i]->isClicked(event, game.getWindow())) {
            game.playClick();
            handleButtonClick(i, game);
            break;
        }
    }
}

void SettingsState::handleButtonClick(int buttonIndex, GameManager& game) {
    switch (buttonIndex) {
        case 0: // Volume -
            game.setVolume(game.getVolume() - 10);
            updateVolumeText(game);
            break;
        case 1: // Volume +
            game.setVolume(game.getVolume() + 10);
            updateVolumeText(game);
            break;
        case 2: // Retour
            game.changeState(std::make_unique<MainMenuState>());
            break;
    }
}

void SettingsState::updateVolumeText(GameManager& game) {
    std::ostringstream volumeStream;
    volumeStream << "Volume: " << static_cast<int>(game.getVolume()) << "%";
    volumeText.setString(volumeStream.str());
}

void SettingsState::update(GameManager& game) {
    updateVolumeText(game);
    
    for (auto& button : buttons) {
        button->update(game.getWindow());
    }
}

void SettingsState::draw(sf::RenderWindow& window) {
    window.draw(titleText);
    window.draw(volumeText);
    
    for (auto& button : buttons) {
        button->draw(window);
    }
}