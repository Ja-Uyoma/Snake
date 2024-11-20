#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Constants.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace snake {

enum class Direction
{
  None,
  Up,
  Down,
  Left,
  Right
};

class Snake
{
public:
  Snake() noexcept;

  /// Get the shape representing the snake
  /// \returns The sf::RectangleShape instance representing the snake's body
  sf::RectangleShape snake() const noexcept;

  /// Set the direction the snake is facing
  /// \param[in] direction The direction the snake is facing
  void setDirection(Direction const& direction) noexcept;

  /// Get the direction the snake is facing
  /// \returns The direction the snake is facing
  Direction const& getDirection() const noexcept;

  /// Move the snake within the window
  void move() noexcept;

  /// Get the position of the head of the snake
  sf::Vector2i position() const noexcept;

  /// Increase the size of the snake
  void grow();

  /// Decrease the size of the snake
  void shrink();

  /// Draw the snake in the window
  /// \param[in] snake The snake to be drawn
  /// \param[in] window The window to draw in
  friend void drawSnake(Snake& snake, sf::RenderWindow& window);

  /// Shrink the snake whenever it collides with itself
  /// \param[in] snake The snake to be shrunk upon collision with itself
  friend void shrinkSnakeOnCollision(Snake& snake);

private:
  sf::RectangleShape m_body {sf::Vector2f(BlockSize, BlockSize)};
  std::vector<sf::Vector2i> m_positions {};
  Direction m_direction {Direction::None};
};

/// Set the direction the snake is facing
/// \param[in] snake The snake whose direction is to be set
void setSnakeDirection(Snake& snake);

}   // namespace snake

#endif
