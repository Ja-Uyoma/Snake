#include "Game.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace snake {

/// Run the game
void Game::run()
{
  while (m_window.isOpen()) {
    sf::Event event;

    while (m_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        m_window.close();
      }
    }

    m_window.clear();
    m_window.draw(m_fruit.getShape());
    drawSnake(m_snake, m_window);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      m_snake.setDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      m_snake.setDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      m_snake.setDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      m_snake.setDirection(Direction::Right);
    }

    m_snake.move();
    m_window.display();
  }
}

}   // namespace snake
