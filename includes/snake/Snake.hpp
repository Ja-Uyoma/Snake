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
  sf::RectangleShape const& snake() const noexcept;

  /// Set the direction the snake is facing
  /// \param[in] direction The direction the snake is facing
  void setDirection(Direction const& direction) noexcept;

  /// Get the direction the snake is facing
  /// \returns The direction the snake is facing
  Direction const& getDirection() const noexcept;

  /// Move the snake within the window
  void move() noexcept;

  /// Get the position of the head of the snake
  sf::Vector2i const& position() const noexcept;

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
