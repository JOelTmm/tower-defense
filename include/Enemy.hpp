#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>

class Enemy {
private:
    std::vector<std::pair<int, int>> path;
    int currentWaypoint;
    int health;
    int x, y; // Coordonnées actuelles
    sf::RectangleShape shape;

public:
    Enemy(const std::vector<std::pair<int, int>>& p, int h) : path(p), currentWaypoint(0), health(h), x(p[0].first * 50), y(p[0].second * 50) {
        shape.setSize(sf::Vector2f(20, 20));
        shape.setFillColor(sf::Color::Red);
    }

    bool isAlive() const { return health > 0; }
    void moveTowards(int targetX, int targetY) {
        int dx = targetX - x;
        int dy = targetY - y;
        if (dx * dx + dy * dy > 25) { // Distance minimale de 5 pixels
            x += dx / 10;
            y += dy / 10;
        } else if (currentWaypoint < path.size() - 1) {
            currentWaypoint++;
            x = path[currentWaypoint].first * 50;
            y = path[currentWaypoint].second * 50;
        }
        shape.setPosition(x, y);
    }
    int getX() const { return x; }
    int getY() const { return y; }
    bool hasReachedEnd() const { return currentWaypoint >= path.size() - 1; }
    void takeDamage(int damage) { health -= damage; }
    void render(sf::RenderWindow& window) {
        if (isAlive()) {
            sf::Vector2f position(x, y);
            shape.setPosition(position);

            // Barre de vie
            sf::RectangleShape healthBar(sf::Vector2f(health * 0.5f, 5));
            healthBar.setPosition(position.x, position.y - 10);
            healthBar.setFillColor(sf::Color::Green);
            window.draw(healthBar);
            window.draw(shape);
        }
    }
};

#endif