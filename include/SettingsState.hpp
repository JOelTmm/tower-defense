#ifndef SETTINGS_STATE_HPP
#define SETTINGS_STATE_HPP

#include "GameState.hpp"
#include "ButtonFactory.hpp"
#include <memory>

class Game; // Forward declaration

// SettingsState.hpp
class SettingsState : public GameState {
private:
    ButtonFactory& buttonFactory;
    std::unique_ptr<ButtonText> backButton;
public:
    SettingsState(ButtonFactory& factory);
    void handleEvent(sf::Event& event, sf::RenderWindow& window, Game& game) override;
    void update(Game& game) override;
    void draw(sf::RenderWindow& window) override;
};

#endif // SETTINGS_STATE_HPP
