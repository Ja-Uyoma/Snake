#include "Game.hpp"

#include "Constants.hpp"
#include "Fruit.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

namespace snake {

/// Run the game
void Game::run() const
{
  sf::RenderWindow window(sf::VideoMode(Window::Width, Window::Height), "Snake");
  Fruit const fruit {sf::Vector2i(Window::Width / 2, Window::Height / 2)};

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(fruit.getShape());
    window.display();
  }
}

}   // namespace snake
