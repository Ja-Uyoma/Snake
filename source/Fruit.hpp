#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "Constants.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {

class Fruit
{
public:
  /// Create a new Fruit instance
  Fruit() noexcept;

  /// Create a new Fruit instance with the given position
  /// \param[in] The position of the fruit
  explicit Fruit(sf::Vector2f const& position) noexcept;

  /// Set the position of the fruit
  /// \param[in] position The new position of the fruit
  void setPosition(sf::Vector2f const& position) noexcept;

  /// Get the position of the fruit
  /// \returns The position of the fruit
  sf::Vector2f getPosition() const noexcept;

  /// Get the shape representing the fruit
  /// \returns The shape representing the fruit
  sf::CircleShape getShape() const noexcept;

private:
  sf::Vector2f m_position {};
  sf::CircleShape m_shape {static_cast<float>(BlockSize) / 2};
};

}   // namespace snake

#endif
