#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

#include "GameState.hpp"
#include "ResourceManager.hpp"
#include "Map.hpp"
#include "Tower.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>

class GameView : public GameState {
private:
    sf::Font* font;
    sf::Text hudText;
    sf::Text goldText;
    sf::Text livesText;
    sf::Text waveText;
    sf::Text scoreText;
    
    std::unique_ptr<Map> gameMap;
    std::vector<std::unique_ptr<Tower>> towers;
    std::vector<std::unique_ptr<Enemy>> enemies;
    
    sf::Clock enemySpawnClock;
    sf::Clock gameUpdateClock;
    
    int enemiesSpawned;
    int enemiesPerWave;
    bool waveActive;
    
    // UI Elements
    sf::RectangleShape hudBackground;
    sf::RectangleShape pauseButton;
    sf::RectangleShape towerMenuButton;
    
public:
    GameView();
    void handleEvent(sf::Event& event, GameManager& game) override;
    void update(GameManager& game) override;
    void draw(sf::RenderWindow& window) override;
    
private:
    void setupUI();
    void spawnEnemy();
    void updateTowers();
    void updateEnemies();
    void checkCollisions();
    void updateHUD(GameManager& game);
    void handleTowerPlacement(sf::Vector2f mousePos, GameManager& game);
};

#endif