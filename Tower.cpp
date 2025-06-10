#include "Tower.hpp"
#include <iostream>
#include <algorithm>

Tower::Tower(int price, float speed, float range, std::string name)
    : price(price), attackSpeed(speed), range(range), level(1), name(name) {}

int Tower::getPrice() const {
    return price;
}

std::string Tower::getName() const {
    return name;
}

void Tower::upgrade() {
    level++;
    price += 2;
    std::cout << name << " évolue au niveau " << level << " (nouveau prix: " << price << ")\n";
}

void Tower::sell() {
    std::cout << name << " vendue pour " << (price / 2) << " pièces.\n";
}

void Tower::accelerate() {
    if (attackSpeed < 3.0f) {
        attackSpeed = std::min(attackSpeed * 2.0f, 3.0f);
        std::cout << name << " accélérée à " << attackSpeed << " attaques/sec.\n";
    } else {
        std::cout << name << " est déjà à vitesse maximale !\n";
    }
}

// BasicTower
BasicTower::BasicTower()
    : Tower(10, 1.0f, 3.0f, "Tour Basique") {}

void BasicTower::attack() {
    std::cout << "Tour Basique attaque à portée " << range << " avec vitesse " << attackSpeed << "\n";
}

// SniperTower
SniperTower::SniperTower()
    : Tower(20, 0.5f, 8.0f, "Tour Sniper") {}

void SniperTower::attack() {
    std::cout << "Tour Sniper attaque à longue portée " << range << " avec vitesse " << attackSpeed << "\n";
}

// Factory
std::shared_ptr<Tower> TowerFactory::createTower(TowerType type) {
    if (type == TowerType::BASIC) {
        return std::make_shared<BasicTower>();
    } else if (type == TowerType::SNIPER) {
        return std::make_shared<SniperTower>();
    }
    return nullptr;
}