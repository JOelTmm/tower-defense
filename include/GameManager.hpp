#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // Ajout de l'en-tête audio
#include <memory>
#include <vector>

class GameState;

class GameManager {
private:
    GameManager();
    ~GameManager() = default;
    static GameManager* instance;
    sf::RenderWindow window;
    std::unique_ptr<GameState> currentState;
    int gold = 100;
    int lives = 10;
    int score = 0;
    int wave = 1;
    sf::SoundBuffer ambianceBuffer, clickBuffer, victoryBuffer, defeatBuffer;
    sf::Sound ambianceSound, clickSound, victorySound, defeatSound;
    float volume = 50.0f;

public:
    static GameManager& getInstance();
    void run();
    void changeState(std::unique_ptr<GameState> newState);
    sf::RenderWindow& getWindow() { return window; }
    int getGold() const { return gold; }
    void addGold(int amount) { gold += amount; }
    void spendGold(int amount) { gold = std::max(0, gold - amount); }
    int getLives() const { return lives; }
    void loseLife() { --lives; }
    int getScore() const { return score; }
    void addScore(int amount) { score += amount; }
    int getWave() const { return wave; }
    void nextWave() { ++wave; }
    float getVolume() const { return volume; }
    void setVolume(float v) { volume = std::max(0.0f, std::min(100.0f, v)); ambianceSound.setVolume(volume); }
    void playClick() { clickSound.play(); }
    void playVictory() { victorySound.play(); }
    void playDefeat() { defeatSound.play(); }
    void playAmbiance() { ambianceSound.play(); ambianceSound.setLoop(true); }
};

#endif