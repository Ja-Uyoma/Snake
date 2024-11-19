#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Constants.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {

class Snake
{
public:
  Snake() noexcept;

  sf::RectangleShape m_body {sf::Vector2f(BlockSize, BlockSize)};
};

}   // namespace snake

#endif
