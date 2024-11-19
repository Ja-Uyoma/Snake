#include "Game.hpp"

#include "Constants.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace snake {

/// Run the game
void Game::run() const
{
  sf::RenderWindow window(sf::VideoMode(Window::Width, Window::Height), "Snake");
  Fruit const fruit {sf::Vector2i(Window::Width / 2, Window::Height / 2)};
  Snake snake;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(fruit.getShape());
    drawSnake(snake, window);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      snake.setDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      snake.setDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      snake.setDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      snake.setDirection(Direction::Right);
    }

    snake.move();
    window.display();
  }
}

}   // namespace snake
