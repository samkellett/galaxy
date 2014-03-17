#include "mixins/gameable.h"

namespace gxy {
namespace mixins {

Gameable::Gameable(Game &game) :
  game_(game)
{
}

void Gameable::setGame(Game &game)
{
  game_ = game;
}

Game &Gameable::game() const
{
  assert(game_);
  return *game_;
}

} // namespace mixins
} // namespace gxy
