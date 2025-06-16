#include "../include/PauseState.hpp"
  #include "../include/MainMenuState.hpp"

  PauseState::PauseState(ButtonFactory& factory) : buttonFactory(factory) {
      volumeUpButton = buttonFactory.createTextButton({100, 50}, L"+");
      volumeDownButton = buttonFactory.createTextButton({100, 50}, L"-");
      quitButton = buttonFactory.createTextButton({200, 50}, L"Quitter");
      resumeButton = buttonFactory.createTextButton({200, 50}, L"Reprendre");

      volumeUpButton->setPosition({300, 300});
      volumeDownButton->setPosition({410, 300});
      quitButton->setPosition({300, 400});
      resumeButton->setPosition({300, 470});
  }

  void PauseState::handleEvent(sf::Event& event, GameManager& game) {
      volumeUpButton->update(game.getWindow());
      volumeDownButton->update(game.getWindow());
      quitButton->update(game.getWindow());
      resumeButton->update(game.getWindow());

      if (volumeUpButton->isClicked(event, game.getWindow())) {
          game.setVolume(game.getVolume() + 10);
      }
      if (volumeDownButton->isClicked(event, game.getWindow())) {
          game.setVolume(game.getVolume() - 10);
      }
      if (quitButton->isClicked(event, game.getWindow())) {
          game.getWindow().close();
      }
      if (resumeButton->isClicked(event, game.getWindow())) {
          // Revenir à l'état précédent (à implémenter selon l'état précédent)
      }
  }

  void PauseState::update(GameManager& game) {}

  void PauseState::draw(sf::RenderWindow& window) {
      volumeUpButton->draw(window);
      volumeDownButton->draw(window);
      quitButton->draw(window);
      resumeButton->draw(window);

      sf::Text title(L"Pause", buttonFactory.getFont(), 40);
      title.setFillColor(sf::Color::White);
      title.setPosition(350, 100);
      window.draw(title);

      sf::Text volumeText(L"Volume: " + std::to_wstring(static_cast<int>(game.getVolume())), buttonFactory.getFont(), 30);
      volumeText.setFillColor(sf::Color::White);
      volumeText.setPosition(300, 250);
      window.draw(volumeText);
  }