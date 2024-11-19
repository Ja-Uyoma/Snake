#include "Snake.hpp"

#include "Constants.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace snake {

Snake::Snake() noexcept
{
  m_body.setFillColor(sf::Color::Green);
  m_positions.reserve(10);
  m_positions.emplace_back(9 * BlockSize, 10 * BlockSize);
  m_positions.emplace_back(10 * BlockSize, 10 * BlockSize);
}

/// Get the shape representing the snake
/// \returns The sf::RectangleShape instance representing the snake's body
sf::RectangleShape Snake::snake() const noexcept
{
  return m_body;
}

/// Move the snake within the window
void Snake::move() noexcept
{
  m_positions.front().x += 1;
}

/// Draw the snake in the window
/// \param[in] snake The snake to be drawn
/// \param[in] window The window to draw in
void drawSnake(Snake& snake, sf::RenderWindow& window)
{
  for (auto const& pos : snake.m_positions) {
    snake.m_body.setPosition(sf::Vector2f(pos));
    window.draw(snake.snake());
  }
}

}   // namespace snake
