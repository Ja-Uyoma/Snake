// MIT License
//
// Copyright (c) 2024 jomondi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
