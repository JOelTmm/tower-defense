#include "GameView.hpp"
#include <sstream>
#include <cmath>

GameView::GameView() : volume(50.f), soundEnabled(true) {
    if (!font.loadFromFile("assets/arial.ttf")) font = sf::Font();

    // Menu principal
    for (int i = 0; i < 5; ++i) {
        menuRect[i].setSize(sf::Vector2f(200, 50));
        menuRect[i].setPosition(300, 100 + i * 60);
        menuRect[i].setFillColor(sf::Color::White);
    }
    menuText[0].setString("1. Nouvelle Partie");
    menuText[1].setString("2. Score");
    menuText[2].setString("3. Hall of Fame");
    menuText[3].setString("4. Paramètres");
    menuText[4].setString("5. Quitter");
    for (int i = 0; i < 5; ++i) {
        menuText[i].setFont(font);
        menuText[i].setCharacterSize(20);
        menuText[i].setPosition(310, 110 + i * 60);
    }

    // Paramètres
    settingsRect[0].setSize(sf::Vector2f(150, 40)); // Son
    settingsRect[1].setSize(sf::Vector2f(150, 40)); // Résolution
    settingsRect[2].setSize(sf::Vector2f(150, 40)); // Retour
    for (int i = 0; i < 3; ++i) {
        settingsRect[i].setPosition(325, 150 + i * 50);
        settingsRect[i].setFillColor(sf::Color::White);
    }
    settingsText[0].setString("Son");
    settingsText[1].setString("Résolution: 800x600");
    settingsText[2].setString("Retour");
    for (int i = 0; i < 3; ++i) {
        settingsText[i].setFont(font);
        settingsText[i].setCharacterSize(20);
        settingsText[i].setPosition(330, 160 + i * 50);
    }

    // HUD
    hudRect.setSize(sf::Vector2f(200, 80));
    hudRect.setPosition(10, 10);
    hudRect.setFillColor(sf::Color(150, 150, 150, 150));

    // Arrière-plan
    backgroundRect.setSize(sf::Vector2f(800, 600));
    backgroundRect.setFillColor(sf::Color(50, 150, 50));

    // Tours et ennemis
    towerRect.setSize(sf::Vector2f(30, 30));
    towerRect.setFillColor(sf::Color::Green); // BasicTower
    enemyRect.setSize(sf::Vector2f(20, 20));
    enemyRect.setFillColor(sf::Color::Red);

    // Barre de vie
    healthBar.setSize(sf::Vector2f(20, 5));
    healthBar.setFillColor(sf::Color::Green);

    // Son généré
    shotBuffer = sf::SoundBuffer();
    std::vector<sf::Int16> samples(44100 / 10); // 100ms de son
    for (size_t i = 0; i < samples.size(); ++i) {
        samples[i] = 10000 * sin(2 * 3.1415926535 * 440 * i / 44100); // 440 Hz
    }
    shotBuffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
    shotSound.setBuffer(shotBuffer);
    shotSound.setVolume(volume);
}

void GameView::render(sf::RenderWindow& window, GameManager& gameManager) {
    window.clear();
    window.draw(backgroundRect);

    if (gameManager.getGameState() == "menu") {
        for (int i = 0; i < 5; ++i) {
            window.draw(menuRect[i]);
            window.draw(menuText[i]);
        }
    } else if (gameManager.getGameState() == "settings") {
        for (int i = 0; i < 3; ++i) {
            window.draw(settingsRect[i]);
            window.draw(settingsText[i]);
        }
        sf::RectangleShape volumeBar(sf::Vector2f(volume * 2, 20));
        volumeBar.setPosition(330, 160);
        volumeBar.setFillColor(sf::Color::Blue);
        window.draw(volumeBar);
    } else if (gameManager.getGameState() == "playing") {
        // HUD
        std::ostringstream oss;
        oss << "Score: " << gameManager.getScore() << "\nHP: " << gameManager.getLives();
        hudText.setString(oss.str());
        hudText.setFont(font);
        hudText.setCharacterSize(20);
        hudText.setPosition(20, 20);
        window.draw(hudRect);
        window.draw(hudText);

        // Tours
        for (auto tower : gameManager.getTowers()) {
            towerRect.setPosition(tower->getPosition().x, tower->getPosition().y);
            if (tower->getType() == "sniper") towerRect.setFillColor(sf::Color::Blue);
            else towerRect.setFillColor(sf::Color::Green);
            window.draw(towerRect);
        }

        // Ennemis et barres de vie
        for (auto enemy : gameManager.getEnemies()) {
            enemyRect.setPosition(enemy->getPosition().x, enemy->getPosition().y);
            window.draw(enemyRect);
            float healthPercent = enemy->getHp() / 100.0f; // HP max = 100
            healthBar.setSize(sf::Vector2f(20 * healthPercent, 5));
            healthBar.setPosition(enemy->getPosition().x, enemy->getPosition().y - 10);
            window.draw(healthBar);
        }
    }
    window.display();
}

void GameView::setSoundVolume(float vol) {
    volume = vol;
    shotSound.setVolume(volume);
}

void GameView::toggleSound() {
    soundEnabled = !soundEnabled;
    shotSound.setVolume(soundEnabled ? volume : 0);
}