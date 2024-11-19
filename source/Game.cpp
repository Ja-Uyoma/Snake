#include "Game.hpp"

#include "Constants.hpp"
#include "Fruit.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace snake {

/// Run the game
void Game::run() const
{
  sf::RenderWindow window(sf::VideoMode(Window::Width, Window::Height), "Snake");
  Fruit const fruit {sf::Vector2i(Window::Width / 2, Window::Height / 2)};
  sf::RectangleShape snake {sf::Vector2f(BlockSize, BlockSize)};
  snake.setFillColor(sf::Color::Green);
  snake.setPosition(10 * BlockSize, 10 * BlockSize);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(fruit.getShape());
    window.draw(snake);
    window.display();
  }
}

}   // namespace snake
