#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Enemy {
private:
    sf::Vector2f position;
    sf::Vector2f target;
    float hp;
    float maxHp;
    float speed;
    std::string type;
    int reward;
    bool isAlive;
    std::vector<sf::Vector2f> path;
    size_t currentPathIndex;
    
public:
    // Constructeurs
    Enemy(const std::string& enemyType, const sf::Vector2f& startPos);
    Enemy(const std::string& enemyType, const sf::Vector2f& startPos, const std::vector<sf::Vector2f>& enemyPath);
    
    // Méthodes de mise à jour
    void update(float deltaTime);
    void takeDamage(float damage);
    
    // Getters
    sf::Vector2f getPosition() const { return position; }
    float getHp() const { return hp; }
    float getMaxHp() const { return maxHp; }
    float getSpeed() const { return speed; }
    std::string getType() const { return type; }
    int getReward() const { return reward; }
    bool getIsAlive() const { return isAlive; }
    float getHealthPercent() const { return maxHp > 0 ? hp / maxHp : 0; }
    
    // Setters
    void setPosition(const sf::Vector2f& pos) { position = pos; }
    void setPath(const std::vector<sf::Vector2f>& newPath);
    
    // Méthodes utilitaires
    bool hasReachedEnd() const;
    sf::Vector2f getNextTarget() const;
    
private:
    void initializeStats(const std::string& enemyType);
    void moveTowardsTarget(float deltaTime);
    float distance(const sf::Vector2f& a, const sf::Vector2f& b) const;
};

// Factory pour créer les ennemis selon les vagues
class EnemyFactory {
public:
    static std::vector<Enemy> createWave(int waveNumber, const std::vector<sf::Vector2f>& path);
    static Enemy createEnemy(const std::string& type, const sf::Vector2f& startPos, const std::vector<sf::Vector2f>& path);
    
private:
    static std::string getEnemyTypeForWave(int waveNumber, int enemyIndex);
    static int getEnemyCountForWave(int waveNumber);
};

#endif