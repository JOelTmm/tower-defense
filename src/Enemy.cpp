#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

Enemy::Enemy(int x, int y, int hp) : x(x), y(y), hp(hp), targetX(9), targetY(9), speed(1), moving(true) {}

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

void Enemy::moveTowards(int targetX, int targetY) {
    if (!isAlive() || !moving) return;
    int dx = targetX - x;
    int dy = targetY - y;
    if (dx != 0 || dy != 0) {
        int steps = speed;
        while (steps > 0 && (dx != 0 || dy != 0)) {
            if (dx > 0) x++;
            else if (dx < 0) x--;
            if (dy > 0) y++;
            else if (dy < 0) y--;
            dx = targetX - x;
            dy = targetY - y;
            steps--;
        }
    }
}

bool Enemy::hasReachedEnd() const {
    return x == targetX && y == targetY;
}

void Enemy::setTarget(int x, int y) {
    targetX = x;
    targetY = y;
}

void Enemy::render(sf::RenderWindow& window) {
    if (!isAlive()) return;
    sf::RectangleShape enemyShape(sf::Vector2f(40, 40));
    enemyShape.setPosition(x * 50 + 5, y * 50 + 5);
    enemyShape.setFillColor(sf::Color::Red);

    // Barre de vie
    float healthPercent = static_cast<float>(hp) / 20.0f; // HP max = 20
    sf::RectangleShape healthBar(sf::Vector2f(40 * healthPercent, 5));
    healthBar.setPosition(x * 50 + 5, y * 50);
    healthBar.setFillColor(sf::Color::Green);
    window.draw(enemyShape);
    window.draw(healthBar);
}