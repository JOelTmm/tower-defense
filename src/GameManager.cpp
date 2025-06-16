#include "GameManager.hpp"
#include "StartState.hpp"
#include <iostream> // Ajout de l'en-tête manquant

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : window(sf::VideoMode(800, 600), "Tower Defense") {
    if (!ambianceBuffer.loadFromFile("assets/ambiance.wav") ||
        !clickBuffer.loadFromFile("assets/click.wav") ||
        !victoryBuffer.loadFromFile("assets/victory.wav") ||
        !defeatBuffer.loadFromFile("assets/defeat.wav")) {
        std::cerr << "Erreur chargement des sons.\n";
    }
    ambianceSound.setBuffer(ambianceBuffer);
    clickSound.setBuffer(clickBuffer);
    victorySound.setBuffer(victoryBuffer);
    defeatSound.setBuffer(defeatBuffer);
    ambianceSound.setVolume(volume);
    playAmbiance();
    changeState(std::make_unique<StartState>());
}

GameManager& GameManager::getInstance() {
    if (!instance) instance = new GameManager();
    return *instance;
}

void GameManager::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (currentState) currentState->handleEvent(event, *this);
        }
        if (currentState) currentState->update(*this);
        window.clear();
        if (currentState) currentState->draw(window);
        window.display();
    }
}

void GameManager::changeState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}