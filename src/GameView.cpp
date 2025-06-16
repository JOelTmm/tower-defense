#include "GameView.hpp"
#include "PauseState.hpp"
#include "TowerMenuState.hpp"
#include "MainMenuState.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

GameView::GameView() : enemiesSpawned(0), enemiesPerWave(5), waveActive(false) {
    // Chargement de la police
    ResourceManager::getInstance().loadFont("assets/arial.TTF", "gameview");
    font = &ResourceManager::getInstance().getFont("assets/arial.TTF");
    
    // Création de la carte
    gameMap = std::make_unique<Map>(16, 12); // 800x600 avec des cases de 50x50
    
    setupUI();
}

void GameView::setupUI() {
    // Configuration du HUD
    hudBackground.setSize(sf::Vector2f(800, 80));
    hudBackground.setPosition(0, 0);
    hudBackground.setFillColor(sf::Color(0, 0, 0, 128));
    
    // Textes du HUD
    goldText.setFont(*font);
    goldText.setCharacterSize(20);
    goldText.setFillColor(sf::Color::Yellow);
    goldText.setPosition(10, 10);
    
    livesText.setFont(*font);
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::Red);
    livesText.setPosition(10, 35);
    
    waveText.setFont(*font);
    waveText.setCharacterSize(20);
    waveText.setFillColor(sf::Color::White);
    waveText.setPosition(200, 10);
    
    scoreText.setFont(*font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(200, 35);
    
    // Bouton pause
    pauseButton.setSize(sf::Vector2f(80, 30));
    pauseButton.setPosition(600, 10);
    pauseButton.setFillColor(sf::Color::Blue);
    
    // Bouton menu des tours
    towerMenuButton.setSize(sf::Vector2f(100, 30));
    towerMenuButton.setPosition(690, 10);
    towerMenuButton.setFillColor(sf::Color::Green);
}

void GameView::handleEvent(sf::Event& event, GameManager& game) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            game.changeState(std::make_unique<PauseState>());
        }
        if (event.key.code == sf::Keyboard::Space) {
            // Démarrer la prochaine vague
            if (!waveActive) {
                waveActive = true;
                enemiesSpawned = 0;
                enemySpawnClock.restart();
            }
        }
    }
    
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        
        // Vérifier les clics sur les boutons
        if (pauseButton.getGlobalBounds().contains(mousePos)) {
            game.playClick();
            game.changeState(std::make_unique<PauseState>());
        }
        else if (towerMenuButton.getGlobalBounds().contains(mousePos)) {
            game.playClick();
            game.changeState(std::make_unique<TowerMenuState>());
        }
        else if (mousePos.y > 80) { // Clic dans la zone de jeu
            handleTowerPlacement(mousePos, game);
        }
    }
}

void GameView::handleTowerPlacement(sf::Vector2f mousePos, GameManager& game) {
    // Convertir les coordonnées de la souris en coordonnées de grille
    int gridX = static_cast<int>((mousePos.x) / 50);
    int gridY = static_cast<int>((mousePos.y - 80) / 50);
    
    // Vérifier si on peut placer une tour (coût: 50 gold)
    if (game.getGold() >= 50) {
        auto tower = std::make_unique<Tower>(50, 1.0f, 100.0f, "Basic Tower");
        tower->setPosition(gridX * 50 + 25, gridY * 50 + 80 + 25);
        towers.push_back(std::move(tower));
        game.spendGold(50);
        game.playClick();
    }
}

void GameView::update(GameManager& game) {
    // Générer les ennemis
    if (waveActive && enemiesSpawned < enemiesPerWave) {
        if (enemySpawnClock.getElapsedTime().asSeconds() > 2.0f) {
            spawnEnemy();
            enemiesSpawned++;
            enemySpawnClock.restart();
        }
    }
    
    // Vérifier si la vague est terminée
    if (waveActive && enemiesSpawned >= enemiesPerWave && enemies.empty()) {
        waveActive = false;
        game.nextWave();
        game.addGold(20); // Bonus de fin de vague
        enemiesPerWave += 2; // Augmenter la difficulté
    }
    
    updateEnemies();
    updateTowers();
    checkCollisions();
    updateHUD(game);
    
    // Vérifier les conditions de fin de jeu
    if (game.getLives() <= 0) {
        game.playDefeat();
        game.changeState(std::make_unique<MainMenuState>());
    }
}

void GameView::spawnEnemy() {
    // Créer un chemin simple (de gauche à droite)
    std::vector<std::pair<int, int>> path = {
        {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, 
        {6, 6}, {7, 6}, {8, 6}, {9, 6}, {10, 6}, {11, 6},
        {12, 6}, {13, 6}, {14, 6}, {15, 6}
    };
    
    auto enemy = std::make_unique<Enemy>(path, 100);
    enemies.push_back(std::move(enemy));
}

void GameView::updateEnemies() {
    for (auto it = enemies.begin(); it != enemies.end();) {
        if (!(*it)->isAlive()) {
            // Ennemi mort, donner de l'or et des points
            GameManager::getInstance().addGold(10);
            GameManager::getInstance().addScore(100);
            it = enemies.erase(it);
        }
        else if ((*it)->hasReachedEnd()) {
            // Ennemi a atteint la fin, perdre une vie
            GameManager::getInstance().loseLife();
            it = enemies.erase(it);
        }
        else {
            // Déplacer l'ennemi
            (*it)->moveTowards((*it)->getX() + 2, (*it)->getY());
            ++it;
        }
    }
}

void GameView::updateTowers() {
    // Les tours attaquent automatiquement les ennemis à portée
    for (auto& tower : towers) {
        // Logique d'attaque simplifiée
        for (auto& enemy : enemies) {
            if (enemy->isAlive()) {
                float dx = enemy->getX() - (tower->getPosition().first);
                float dy = enemy->getY() - (tower->getPosition().second);
                float distance = std::sqrt(dx * dx + dy * dy);
                
                if (distance <= tower->getRange()) {
                    enemy->takeDamage(25);
                    break; // Une tour ne peut attaquer qu'un ennemi à la fois
                }
            }
        }
    }
}

void GameView::checkCollisions() {
    // Cette méthode peut être étendue pour des collisions plus complexes
}

void GameView::updateHUD(GameManager& game) {
    std::ostringstream goldStream, livesStream, waveStream, scoreStream;
    
    goldStream << "Or: " << game.getGold();
    goldText.setString(goldStream.str());
    
    livesStream << "Vies: " << game.getLives();
    livesText.setString(livesStream.str());
    
    waveStream << "Vague: " << game.getWave();
    waveText.setString(waveStream.str());
    
    scoreStream << "Score: " << game.getScore();
    scoreText.setString(scoreStream.str());
}

void GameView::draw(sf::RenderWindow& window) {
    // Dessiner la carte
    gameMap->render(window);
    
    // Dessiner les tours
    for (auto& tower : towers) {
        tower->render(window);
    }
    
    // Dessiner les ennemis
    for (auto& enemy : enemies) {
        enemy->render(window);
    }
    
    // Dessiner le HUD
    window.draw(hudBackground);
    window.draw(goldText);
    window.draw(livesText);
    window.draw(waveText);
    window.draw(scoreText);
    window.draw(pauseButton);
    window.draw(towerMenuButton);
    
    // Texte d'aide
    sf::Text helpText;
    helpText.setFont(*font);
    helpText.setCharacterSize(16);
    helpText.setFillColor(sf::Color::White);
    helpText.setString("ESPACE: Nouvelle vague | ESC: Pause | Clic: Placer tour (50 gold)");
    helpText.setPosition(10, 550);
    window.draw(helpText);
}

