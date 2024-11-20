#include "Fruit.hpp"

#include "Constants.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <random>

namespace snake {

/// Create a new Fruit instance
Fruit::Fruit() noexcept
{
  m_shape.setFillColor(sf::Color::Green);
}

/// Create a new Fruit instance with the given position
/// \param[in] The position of the fruit
Fruit::Fruit(sf::Vector2i const& position) noexcept : Fruit()
{
  setPosition(position);
}

/// Set the position of the fruit
/// \param[in] position The new position of the fruit
void Fruit::setPosition(sf::Vector2i const& position) noexcept
{
  m_position = position;
  m_shape.setPosition(sf::Vector2f(m_position));
}

/// Get the position of the fruit
/// \returns The position of the fruit
sf::Vector2i const& Fruit::getPosition() const noexcept
{
  return m_position;
}

/// Get the shape representing the fruit
/// \returns The shape representing the fruit
sf::CircleShape const& Fruit::getShape() const noexcept
{
  return m_shape;
}

/// Respawn the fruit elsewhere in the visible window
/// \param[in] The fruit to be respawned
void respawnFruit(Fruit& fruit)
{
  static std::random_device rd {};
  static std::mt19937 generator {rd()};

  static constexpr auto gridX = Window::Width / BlockSize;
  static constexpr auto gridY = Window::Height / BlockSize;

  sf::Vector2i pos {static_cast<int>(generator() % gridX), static_cast<int>(generator() % gridY)};
  fruit.setPosition(pos * BlockSize);
}

}   // namespace snake
