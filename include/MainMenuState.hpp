#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "GameState.hpp"
#include "ButtonFactory.hpp"
#include <memory>

class MainMenuState : public GameState {
private:
    std::unique_ptr<ButtonText> playButton;
    std::unique_ptr<ButtonText> settingsButton;
    ButtonFactory& buttonFactory;

public:
    explicit MainMenuState(ButtonFactory& factory);

    void handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) override;
    void update(Game& game) override;
    void draw(sf::RenderWindow& window) override;
};

#endif
