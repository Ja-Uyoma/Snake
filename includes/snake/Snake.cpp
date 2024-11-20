#include "Snake.hpp"

#include "Constants.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include <iterator>

namespace snake {

Snake::Snake() noexcept
{
  m_body.setFillColor(sf::Color::Green);
  m_positions.reserve(20);
  m_positions.emplace_back(9 * BlockSize, 10 * BlockSize);
  m_positions.emplace_back(10 * BlockSize, 10 * BlockSize);
}

/// Get the shape representing the snake
/// \returns The sf::RectangleShape instance representing the snake's body
sf::RectangleShape const& Snake::snake() const noexcept
{
  return m_body;
}

/// Set the direction the snake is facing
/// \param[in] direction The direction the snake is facing
void Snake::setDirection(Direction const& direction) noexcept
{
  m_direction = direction;
}

/// Get the direction the snake is facing
/// \returns The direction the snake is facing
Direction const& Snake::getDirection() const noexcept
{
  return m_direction;
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
sf::Vector2i const& Snake::position() const noexcept
{
  return m_positions.front();
}

/// Increase the size of the snake
void Snake::grow()
{
  using enum Direction;
  auto const& head = m_positions.front();

  if (m_direction == Up) {
    m_positions.emplace_back(head.x, head.y + (1 * BlockSize));
  }
  else if (m_direction == Down) {
    m_positions.emplace_back(head.x, head.y - (1 * BlockSize));
  }
  else if (m_direction == Left) {
    m_positions.emplace_back(head.x + (1 * BlockSize), head.y);
  }
  else if (m_direction == Right) {
    m_positions.emplace_back(head.x - (1 * BlockSize), head.y);
  }
}

/// Decrease the size of the snake
void Snake::shrink()
{
  m_positions.pop_back();
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

/// Shrink the snake whenever it collides with itself
/// \param[in] snake The snake to be shrunk upon collision with itself
void shrinkSnakeOnCollision(Snake& snake)
{
  auto const& pos = snake.m_positions;

  // Can't have collisions if the size of m_positions is less than 5
  if (pos.size() < 5) {
    return;
  }

  auto const& head = pos.front();
  auto const iter = std::ranges::find_if(
    std::next(pos.cbegin()), pos.cend(), [&head](sf::Vector2i const& position) { return head == position; });

  if (iter != pos.cend()) {
    auto const dropped = std::distance(iter, pos.cend());

    for (auto i = 0; i < dropped; ++i) {
      snake.shrink();
    }
  }
}

/// Set the direction the snake is facing
/// \param[in] snake The snake whose direction is to be set
void setSnakeDirection(Snake& snake)
{
  auto const& direction = snake.getDirection();

  using enum Direction;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and direction != Down) {
    snake.setDirection(Up);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and direction != Up) {
    snake.setDirection(Down);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and direction != Right) {
    snake.setDirection(Left);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and direction != Left) {
    snake.setDirection(Right);
  }
}

}   // namespace snake
