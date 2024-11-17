#include "Constants.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <cstdlib>

namespace snake {

void Main()
{
  sf::RenderWindow window(sf::VideoMode(Window::Width, Window::Height), "Snake");

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.display();
  }
}

}   // namespace snake

int main()
{
  snake::Main();

  return EXIT_SUCCESS;
}
