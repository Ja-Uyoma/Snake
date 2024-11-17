#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace snake {

inline constexpr auto BlockSize {16};

struct Window
{
  static constexpr auto Width {40 * BlockSize};
  static constexpr auto Height {30 * BlockSize};
};

}   // namespace snake

#endif
