#include "game.h"

namespace galaxy {

Game::Game(const char *title) :
  title_(title)
{
}

const char *Game::title() const
{
  return title_;
}

} // namespace galaxy
