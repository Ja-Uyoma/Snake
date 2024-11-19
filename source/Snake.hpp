#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Constants.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {

class Snake
{
public:
  Snake() noexcept;

  /// Get the shape representing the snake
  /// \returns The sf::RectangleShape instance representing the snake's body
  sf::RectangleShape snake() const noexcept;

  /// Draw the snake in the window
  /// \param[in] snake The snake to be drawn
  /// \param[in] window The window to draw in
  friend void drawSnake(Snake& snake, sf::RenderWindow& window);

private:
  sf::RectangleShape m_body {sf::Vector2f(BlockSize, BlockSize)};
};

}   // namespace snake

#endif
