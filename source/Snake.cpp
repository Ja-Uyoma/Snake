#include "Snake.hpp"

#include "Constants.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace snake {

Snake::Snake() noexcept
{
  m_body.setFillColor(sf::Color::Green);
  m_body.setPosition(10 * BlockSize, 10 * BlockSize);
}

/// Get the shape representing the snake
/// \returns The sf::RectangleShape instance representing the snake's body
sf::RectangleShape Snake::snake() const noexcept
{
  return m_body;
}

}   // namespace snake
