#ifndef TOWERMENUSTATE_H
#define TOWERMENUSTATE_H

#include "GameState.hpp"
#include "ButtonFactory.hpp"
#include <memory>

class TowerMenuState : public GameState {
private:
    ButtonFactory& buttonFactory;
    std::unique_ptr<Button> placeButton, upgradeButton, backButton;

public:
    TowerMenuState(ButtonFactory& factory);
    void handleEvent(sf::Event& event, GameManager& game) override;
    void update(GameManager& game) override;
    void draw(sf::RenderWindow& window) override;
};

#endif