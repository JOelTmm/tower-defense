#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameManager.hpp"

class GameView {
public:
    GameView();
    void render(sf::RenderWindow& window, GameManager& gameManager);
    void setSoundVolume(float volume);
    void toggleSound();

private:
    sf::Font font;
    sf::RectangleShape menuRect[5];
    sf::RectangleShape settingsRect[3];
    sf::RectangleShape hudRect;
    sf::RectangleShape backgroundRect;
    sf::RectangleShape towerRect, enemyRect;
    sf::RectangleShape healthBar;
    sf::Text menuText[5], settingsText[3], hudText;
    sf::SoundBuffer shotBuffer;
    sf::Sound shotSound;
    float volume;
    bool soundEnabled;
};

#endif