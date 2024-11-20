#include "Snake.hpp"

#include "Constants.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

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

/// Set the direction the snake is facing
/// \param[in] direction The direction the snake is facing
void Snake::setDirection(Direction const& direction) noexcept
{
  m_direction = direction;
}

/// Move the snake within the window
void Snake::move() noexcept
{
  using enum Direction;

  if (m_direction == None) {
    return;
  }

  for (auto i = std::ssize(m_positions) - 1; i > 0; --i) {
    m_positions[i] = m_positions[i - 1];
  }

  auto& head = m_positions.front();

  if (m_direction == Up) {
    head.y -= 1 * BlockSize;
  }
  else if (m_direction == Down) {
    head.y += 1 * BlockSize;
  }
  else if (m_direction == Left) {
    head.x -= 1 * BlockSize;
  }
  else if (m_direction == Right) {
    head.x += 1 * BlockSize;
  }
}

/// Get the position of the head of the snake
sf::Vector2i Snake::position() const noexcept
{
  return m_positions.front();
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

/// Set the direction the snake is facing
/// \param[in] snake The snake whose direction is to be set
void setSnakeDirection(Snake& snake)
{
  using enum Direction;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    snake.setDirection(Up);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    snake.setDirection(Down);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    snake.setDirection(Left);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    snake.setDirection(Right);
  }
}

}   // namespace snake
