#include "gxy/game.h"

#include "gxy/gfx.h"
#include "gxy/macros.h"

namespace gxy {

game::game() :
  error_code_(0),
  quitting_(false)
{
}

void game::tick()
{
}

void game::quit(const unsigned int error_code)
{
  quitting_ = true;
  error_code_ = error_code;
}

bool game::quitting() const
{
  return quitting_;
}

unsigned int game::error_code() const
{
  return error_code_;
}

} // namespace gxy
