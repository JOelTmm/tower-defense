#include "Tower.hpp"
#include <iostream>
#include <cmath>

Tower::Tower(int price, float speed, float range, std::string name)
    : price(price), attackSpeed(speed), range(range), level(1), name(name), x(-1), y(-1) {}

void Tower::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

std::pair<int, int> Tower::getPosition() const {
    return {x, y};
}

int Tower::getPrice() const {
    return price;
}

std::string Tower::getName() const {
    return name;
}

void Tower::upgrade() {
    level++;
    price += 2;
    std::cout << name << " niveau " << level << " (prix : " << price << ")\n";
}

void Tower::sell() {
    std::cout << name << " vendue pour " << (price / 2) << " pièces.\n";
}

void Tower::accelerate() {
    if (attackSpeed < 3.0f) {
        attackSpeed = std::min(attackSpeed * 2.0f, 3.0f);
        std::cout << name << " accélérée à " << attackSpeed << " attaques/sec.\n";
    } else {
        std::cout << name << " est déjà à la vitesse max.\n";
    }
}

float Tower::getRange() const {
    return range;
}

void Tower::attack(std::vector<std::shared_ptr<Enemy>>& enemies) {
    // Par défaut, rien
}

// BasicTower
BasicTower::BasicTower()
    : Tower(10, 1.0f, 3.0f, "Tour Basique") {}

void BasicTower::attack(std::vector<std::shared_ptr<Enemy>>& enemies) {
    for (auto& enemy : enemies) {
        float dx = x - enemy->getX();
        float dy = y - enemy->getY();
        float distance = std::sqrt(dx * dx + dy * dy);
        if (distance <= range && enemy->isAlive()) {
            enemy->takeDamage(5);
            std::cout << name << " attaque un ennemi à distance " << distance << " (PV restant: " << enemy->getHP() << ")\n";
            break; // n'attaque qu'un ennemi par tour
        }
    }
}

// SniperTower
SniperTower::SniperTower()
    : Tower(20, 0.5f, 8.0f, "Tour Sniper") {}

void SniperTower::attack(std::vector<std::shared_ptr<Enemy>>& enemies) {
    for (auto& enemy : enemies) {
        float dx = x - enemy->getX();
        float dy = y - enemy->getY();
        float distance = std::sqrt(dx * dx + dy * dy);
        if (distance <= range && enemy->isAlive()) {
            enemy->takeDamage(10);
            std::cout << name << " tire avec précision sur un ennemi (PV: " << enemy->getHP() << ")\n";
            break;
        }
    }
}

// Factory
std::shared_ptr<Tower> TowerFactory::createTower(TowerType type) {
    if (type == TowerType::BASIC) return std::make_shared<BasicTower>();
    if (type == TowerType::SNIPER) return std::make_shared<SniperTower>();
    return nullptr;
}
