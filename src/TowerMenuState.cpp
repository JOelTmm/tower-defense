#include "../include/TowerMenuState.hpp"
  #include "../include/GameState.hpp"
  #include "../include/MainMenuState.hpp"

  TowerMenuState::TowerMenuState(ButtonFactory& factory) : buttonFactory(factory) {
      placeButton = buttonFactory.createTextButton({200, 50}, L"Placer Tour");
      upgradeButton = buttonFactory.createTextButton({200, 50}, L"Améliorer Tour");
      backButton = buttonFactory.createTextButton({200, 50}, L"Retour");

      placeButton->setPosition({300, 300});
      upgradeButton->setPosition({300, 370});
      backButton->setPosition({300, 440});
  }

  void TowerMenuState::handleEvent(sf::Event& event, GameManager& game) {
      placeButton->update(game.getWindow());
      upgradeButton->update(game.getWindow());
      backButton->update(game.getWindow());

      if (placeButton->isClicked(event, game.getWindow())) {
          if (game.getGold() >= 10) {
              game.spendGold(10); // Exemple de placement
              game.playClick();
          }
      }
      if (upgradeButton->isClicked(event, game.getWindow())) {
          if (game.getGold() >= 20) {
              game.spendGold(20); // Exemple d'amélioration
              game.playClick();
          }
      }
      if (backButton->isClicked(event, game.getWindow())) {
          game.changeState(std::make_unique<MainMenuState>(buttonFactory));
      }
  }

  void TowerMenuState::update(GameManager& game) {}

  void TowerMenuState::draw(sf::RenderWindow& window) {
      placeButton->draw(window);
      upgradeButton->draw(window);
      backButton->draw(window);

      sf::Text title(L"Menu Tours", buttonFactory.getFont(), 40);
      title.setFillColor(sf::Color::White);
      title.setPosition(300, 100);
      window.draw(title);
  }