#include "Game.hpp"

#include "Constants.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace snake {

/// Run the game
void Game::run()
{
  auto elapsedTime {m_clock.getElapsedTime()};

  // time = distance ÷ speed
  // The fixed timeStep is the time the snake takes to cover a single block (or grid cell) in the game world
  static constexpr auto timeStep {1.0f / BlockSize};

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

    setSnakeDirection(m_snake);

    if (elapsedTime > sf::seconds(timeStep)) {
      m_snake.move();

      if (m_snake.position() == m_fruit.getPosition()) {
        m_snake.grow();
        respawnFruit(m_fruit);
      }

      elapsedTime -= sf::seconds(timeStep);
    }

    elapsedTime += m_clock.restart();
    m_window.display();
  }
}

}   // namespace snake
