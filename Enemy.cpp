#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int hp) : x(x), y(y), hp(hp) {}

void Enemy::takeDamage(int dmg) {
    hp -= dmg;
    if (hp < 0) hp = 0;
}

bool Enemy::isAlive() const {
    return hp > 0;
}

int Enemy::getX() const { return x; }
int Enemy::getY() const { return y; }
int Enemy::getHP() const { return hp; }
