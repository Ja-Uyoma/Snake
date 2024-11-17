#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <cstdlib>

inline constexpr auto BlockSize {16};

struct Window
{
  static constexpr auto Width {40 * BlockSize};
  static constexpr auto Height {30 * BlockSize};
};

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

int main()
{
  Main();

  return EXIT_SUCCESS;
}
