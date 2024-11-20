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

#ifndef GAME_HPP
#define GAME_HPP

#include "Constants.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace snake {

class Game
{
public:
  /// Create a default Game instance
  Game() noexcept = default;

  /// Run the game
  void run();

private:
  sf::RenderWindow m_window {sf::VideoMode(Window::Width, Window::Height), "Snake"};
  Fruit m_fruit {sf::Vector2i(Window::Width / 2, Window::Height / 2)};
  Snake m_snake {};
  sf::Clock m_clock {};

  /// Process game updates that happen during a single cycle
  void tick();
};

}   // namespace snake

#endif
