#include "Enemy.hpp"
#include <cmath>
#include <iostream>

// Constructeur basique
Enemy::Enemy(const std::string& enemyType, const sf::Vector2f& startPos) 
    : position(startPos), target(startPos), currentPathIndex(0), isAlive(true) {
    initializeStats(enemyType);
    
    // Chemin par défaut (ligne droite vers la droite)
    path.push_back(startPos);
    path.push_back(sf::Vector2f(800, startPos.y));
}

// Constructeur avec chemin personnalisé
Enemy::Enemy(const std::string& enemyType, const sf::Vector2f& startPos, const std::vector<sf::Vector2f>& enemyPath)
    : position(startPos), currentPathIndex(0), isAlive(true) {
    initializeStats(enemyType);
    setPath(enemyPath);
    
    if (!path.empty()) {
        target = path[0];
    }
}

void Enemy::initializeStats(const std::string& enemyType) {
    type = enemyType;
    
    if (enemyType == "basic") {
        maxHp = 50.0f;
        speed = 30.0f;
        reward = 10;
    } else if (enemyType == "fast") {
        maxHp = 30.0f;
        speed = 60.0f;
        reward = 15;
    } else if (enemyType == "tank") {
        maxHp = 150.0f;
        speed = 15.0f;
        reward = 25;
    } else if (enemyType == "flying") {
        maxHp = 40.0f;
        speed = 45.0f;
        reward = 20;
    } else {
        // Type par défaut
        maxHp = 50.0f;
        speed = 30.0f;
        reward = 10;
    }
    
    hp = maxHp;
}

void Enemy::update(float deltaTime) {
    if (!isAlive) return;
    
    moveTowardsTarget(deltaTime);
    
    // Vérifier si on a atteint la cible actuelle
    if (distance(position, target) < 5.0f) {
        currentPathIndex++;
        if (currentPathIndex < path.size()) {
            target = path[currentPathIndex];
        }
    }
}

void Enemy::moveTowardsTarget(float deltaTime) {
    sf::Vector2f direction = target - position;
    float dist = distance(position, target);
    
    if (dist > 0) {
        // Normaliser la direction
        direction /= dist;
        
        // Déplacer l'ennemi
        position += direction * speed * deltaTime;
    }
}

void Enemy::takeDamage(float damage) {
    if (!isAlive) return;
    
    hp -= damage;
    if (hp <= 0) {
        hp = 0;
        isAlive = false;
    }
}

bool Enemy::hasReachedEnd() const {
    return currentPathIndex >= path.size();
}

sf::Vector2f Enemy::getNextTarget() const {
    if (currentPathIndex + 1 < path.size()) {
        return path[currentPathIndex + 1];
    }
    return target;
}

void Enemy::setPath(const std::vector<sf::Vector2f>& newPath) {
    path = newPath;
    currentPathIndex = 0;
    if (!path.empty()) {
        target = path[0];
    }
}

float Enemy::distance(const sf::Vector2f& a, const sf::Vector2f& b) const {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Implémentation EnemyFactory
std::vector<Enemy> EnemyFactory::createWave(int waveNumber, const std::vector<sf::Vector2f>& path) {
    std::vector<Enemy> enemies;
    int enemyCount = getEnemyCountForWave(waveNumber);
    
    sf::Vector2f startPos = path.empty() ? sf::Vector2f(0, 300) : path[0];
    
    for (int i = 0; i < enemyCount; ++i) {
        std::string enemyType = getEnemyTypeForWave(waveNumber, i);
        
        // Décaler les ennemis pour éviter qu'ils se chevauchent
        sf::Vector2f spawnPos = startPos;
        spawnPos.x -= i * 40; // Espacement de 40 pixels
        
        Enemy enemy(enemyType, spawnPos, path);
        enemies.push_back(enemy);
    }
    
    return enemies;
}

Enemy EnemyFactory::createEnemy(const std::string& type, const sf::Vector2f& startPos, const std::vector<sf::Vector2f>& path) {
    return Enemy(type, startPos, path);
}

std::string EnemyFactory::getEnemyTypeForWave(int waveNumber, int enemyIndex) {
    // Logique pour déterminer le type d'ennemi selon la vague
    if (waveNumber >= 15) {
        // Vagues avancées : mélange de tous les types
        switch (enemyIndex % 4) {
            case 0: return "tank";
            case 1: return "fast";
            case 2: return "flying";
            default: return "basic";
        }
    } else if (waveNumber >= 10) {
        // Introduction des ennemis volants
        switch (enemyIndex % 3) {
            case 0: return "flying";
            case 1: return "fast";
            default: return "basic";
        }
    } else if (waveNumber >= 5) {
        // Introduction des tanks et ennemis rapides
        switch (enemyIndex % 3) {
            case 0: return "tank";
            case 1: return "fast";
            default: return "basic";
        }
    } else if (waveNumber >= 3) {
        // Introduction des ennemis rapides
        return (enemyIndex % 2 == 0) ? "fast" : "basic";
    } else {
        // Premières vagues : seulement des ennemis basiques
        return "basic";
    }
}

int EnemyFactory::getEnemyCountForWave(int waveNumber) {
    // Nombre d'ennemis augmente progressivement
    if (waveNumber <= 5) {
        return 3 + waveNumber;
    } else if (waveNumber <= 10) {
        return 8 + (waveNumber - 5) * 2;
    } else if (waveNumber <= 20) {
        return 18 + (waveNumber - 10) * 3;
    } else {
        return 48 + (waveNumber - 20) * 4;
    }
}