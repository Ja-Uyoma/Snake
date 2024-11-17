#include "Fruit.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {

/// Create a new Fruit instance
Fruit::Fruit() noexcept
{
  m_shape.setFillColor(sf::Color::Green);
}

/// Create a new Fruit instance with the given position
/// \param[in] The position of the fruit
Fruit::Fruit(sf::Vector2f const& position) noexcept : Fruit()
{
  setPosition(position);
}

/// Set the position of the fruit
/// \param[in] position The new position of the fruit
void Fruit::setPosition(sf::Vector2f const& position) noexcept
{
  m_position = position;
  m_shape.setPosition(m_position);
}

/// Get the position of the fruit
/// \returns The position of the fruit
sf::Vector2f Fruit::getPosition() const noexcept
{
  return m_position;
}

/// Get the shape representing the fruit
/// \returns The shape representing the fruit
sf::CircleShape Fruit::getShape() const noexcept
{
  return m_shape;
}

}   // namespace snake
