#include "GameManager.hpp"

int main() {
    GameManager& game = GameManager::getInstance();
    game.run();
    return 0;
}