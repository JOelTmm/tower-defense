#ifndef BUTTON_H
  #define BUTTON_H

  #include <SFML/Graphics.hpp>
  #include <memory>

  class Button {
  public:
      virtual ~Button() = default;
      virtual void update(sf::RenderWindow& window) = 0;
      virtual bool isClicked(sf::Event& event, sf::RenderWindow& window) = 0;
      virtual void draw(sf::RenderWindow& window) = 0;
      virtual void setPosition(sf::Vector2f pos) = 0;
  };

  #endif