#pragma once

#include <chrono>

namespace gxy {

class game
{
public:
  game();

  void tick();

  void initialise();
  void teardown();

  void quit(const unsigned int error_code);
  bool quitting() const;

  unsigned int error_code() const;
  const std::chrono::nanoseconds &dt() const;

private:
  unsigned int error_code_;
  bool quitting_;

  std::chrono::nanoseconds dt_;
};

} // namespace gxy
