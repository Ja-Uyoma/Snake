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

    drawFruit(m_fruit, m_window);
    drawSnake(m_snake, m_window);

    setSnakeDirection(m_snake);

    if (elapsedTime > sf::seconds(timeStep)) {
      tick();
      elapsedTime -= sf::seconds(timeStep);
    }

    elapsedTime += m_clock.restart();
    m_window.display();
  }
}

/// Process game updates that happen during a single cycle
void Game::tick()
{
  m_snake.move();

  if (m_snake.position() == m_fruit.getPosition()) {
    m_snake.grow();
    respawnFruit(m_fruit);
  }

  shrinkSnakeOnCollision(m_snake);
}

}   // namespace snake
