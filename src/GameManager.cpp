#include "GameManager.hpp"
#include "StartState.hpp"
#include "ResourceManager.hpp"
#include <iostream>

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : window(sf::VideoMode(800, 600), "Tower Defense") {
    // Chargement des sons via ResourceManager
    ResourceManager& resources = ResourceManager::getInstance();
    
    if (!resources.loadSoundBuffer("assets/ambiance.wav", "ambiance") ||
        !resources.loadSoundBuffer("assets/click.wav", "click") ||
        !resources.loadSoundBuffer("assets/victory.wav", "victory") ||
        !resources.loadSoundBuffer("assets/defeat.wav", "defeat")) {
        std::cerr << "Erreur chargement des sons.\n";
    }
    
    // Configuration des sons
    ambianceSound.setBuffer(resources.getSoundBuffer("assets/ambiance.wav"));
    clickSound.setBuffer(resources.getSoundBuffer("assets/click.wav"));
    victorySound.setBuffer(resources.getSoundBuffer("assets/victory.wav"));
    defeatSound.setBuffer(resources.getSoundBuffer("assets/defeat.wav"));
    
    ambianceSound.setVolume(volume);
    clickSound.setVolume(volume);
    victorySound.setVolume(volume);
    defeatSound.setVolume(volume);
    
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
        window.clear(sf::Color::Black);
        if (currentState) currentState->draw(window);
        window.display();
    }
}

void GameManager::changeState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}