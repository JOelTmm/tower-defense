#ifndef TOWER_HPP
#define TOWER_HPP

#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

enum class TowerType { BASIC, SNIPER };

class Tower {
protected:
    int level;
    int price;
    float attackSpeed;
    float range;
    std::string name;
    int x, y; // Position sur la carte

public:
    Tower(int price, float speed, float range, std::string name);
    virtual ~Tower() = default;

    void setPosition(int x, int y);
    std::pair<int, int> getPosition() const;

    virtual void attack(std::vector<std::shared_ptr<Enemy>>& enemies);
    int getPrice() const;
    std::string getName() const;
    void upgrade();
    void sell();
    void accelerate();
    float getRange() const;
    virtual void render(sf::RenderWindow& window); // Méthode virtuelle ajoutée
};

class BasicTower : public Tower {
public:
    BasicTower();
    void attack(std::vector<std::shared_ptr<Enemy>>& enemies) override;
    void render(sf::RenderWindow& window) override;
};

class SniperTower : public Tower {
public:
    SniperTower();
    void attack(std::vector<std::shared_ptr<Enemy>>& enemies) override;
    void render(sf::RenderWindow& window) override;
};

class TowerFactory {
public:
    static std::shared_ptr<Tower> createTower(TowerType type);
};

#endif