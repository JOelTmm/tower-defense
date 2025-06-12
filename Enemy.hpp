#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
    int x, y;
    int hp;

public:
    Enemy(int x, int y, int hp);
    void takeDamage(int dmg);
    bool isAlive() const;
    int getX() const;
    int getY() const;
    int getHP() const;
};

#endif