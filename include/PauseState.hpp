#ifndef PAUSESTATE_H
  #define PAUSESTATE_H

  #include "GameState.hpp"
  #include "ButtonFactory.hpp" // Assure-toi que ce fichier est dans include/
  #include <memory>

  class PauseState : public GameState {
  private:
      ButtonFactory& buttonFactory;
      std::unique_ptr<Button> volumeUpButton, volumeDownButton, quitButton, resumeButton;

  public:
      PauseState(ButtonFactory& factory);
      void handleEvent(sf::Event& event, GameManager& game) override;
      void update(GameManager& game) override;
      void draw(sf::RenderWindow& window) override;
  };

  #endif