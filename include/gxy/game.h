#pragma once

namespace gxy {

class game
{
public:
  game();

  void tick();

  void quit(const unsigned int error_code);
  bool quitting() const;

  unsigned int error_code() const;

private:
  unsigned int error_code_;
  bool quitting_;
};

} // namespace gxy
