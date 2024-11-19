#include "Snake.hpp"

#include "Constants.hpp"
#include <SFML/Graphics/Color.hpp>

namespace snake {

Snake::Snake() noexcept
{
  m_body.setFillColor(sf::Color::Green);
  m_body.setPosition(10 * BlockSize, 10 * BlockSize);
}

}   // namespace snake
