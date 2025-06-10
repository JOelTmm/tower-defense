#ifndef TOWER_HPP
#define TOWER_HPP

#include <string>
#include <memory>

enum class TowerType { BASIC, SNIPER };

class Tower {
protected:
    int level;
    int price;
    float attackSpeed; // attaques par seconde
    float range;
    std::string name;

public:
    Tower(int price, float speed, float range, std::string name);
    virtual ~Tower() = default;

    virtual void attack() = 0;
    virtual int getPrice() const;
    virtual std::string getName() const;
    virtual void upgrade(); // +2 prix
    virtual void sell();    // Affiche prix/2
    virtual void accelerate(); // Vitesse * 2 jusqu’à max 3
};

class BasicTower : public Tower {
public:
    BasicTower();
    void attack() override;
};

class SniperTower : public Tower {
public:
    SniperTower();
    void attack() override;
};

class TowerFactory {
public:
    static std::shared_ptr<Tower> createTower(TowerType type);
};

#endif // TOWER_HPP