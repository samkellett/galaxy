#include "mixins/gameable.h"

namespace gxy {
namespace mixins {

Gameable::Gameable(std::shared_ptr<Game> game) :
  game_(game)
{
}

void Gameable::setGame(const std::shared_ptr<Game> game)
{
  game_ = game;
}

std::shared_ptr<Game> Gameable::game()
{
  return game_;
}

std::shared_ptr<Game> Gameable::game() const
{
  return game_;
}

} // namespace mixins
} // namespace gxy
