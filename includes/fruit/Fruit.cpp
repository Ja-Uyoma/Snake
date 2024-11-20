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

/// Draw the given fruit in the window
/// \param[in] fruit The fruit to be drawn
/// \param[in] window The window it is drawn in
void drawFruit(Fruit const& fruit, sf::RenderWindow& window)
{
  window.draw(fruit.getShape());
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
