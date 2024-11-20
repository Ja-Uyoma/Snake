#ifndef GAME_HPP
#define GAME_HPP

#include "Constants.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace snake {

class Game
{
public:
  /// Create a default Game instance
  Game() noexcept = default;

  /// Run the game
  void run();

private:
  sf::RenderWindow m_window {sf::VideoMode(Window::Width, Window::Height), "Snake"};
  Fruit m_fruit {sf::Vector2i(Window::Width / 2, Window::Height / 2)};
  Snake m_snake {};
  sf::Clock m_clock {};
};

}   // namespace snake

#endif
