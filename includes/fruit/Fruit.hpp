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

#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "Constants.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {

class Fruit
{
public:
  /// Create a new Fruit instance
  Fruit() noexcept;

  /// Create a new Fruit instance with the given position
  /// \param[in] The position of the fruit
  explicit Fruit(sf::Vector2i const& position) noexcept;

  /// Set the position of the fruit
  /// \param[in] position The new position of the fruit
  void setPosition(sf::Vector2i const& position) noexcept;

  /// Get the position of the fruit
  /// \returns The position of the fruit
  sf::Vector2i const& getPosition() const noexcept;

  /// Get the shape representing the fruit
  /// \returns The shape representing the fruit
  sf::CircleShape const& getShape() const noexcept;

private:
  sf::Vector2i m_position {};
  sf::CircleShape m_shape {static_cast<float>(BlockSize) / 2};
};

/// Draw the given fruit in the window
/// \param[in] fruit The fruit to be drawn
/// \param[in] window The window it is drawn in
void drawFruit(Fruit const& fruit, sf::RenderWindow& window);

/// Respawn the fruit elsewhere in the visible window
/// \param[in] The fruit to be respawned
void respawnFruit(Fruit& fruit);

}   // namespace snake

#endif
