#ifndef GAME_HPP
#define GAME_HPP

namespace snake {

class Game
{
public:
  /// Create a default Game instance
  Game() noexcept = default;

  /// Run the game
  void run() const;
};

}   // namespace snake

#endif
