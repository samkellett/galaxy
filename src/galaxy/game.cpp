#include "game.h"

namespace galaxy {

Game::Game(const char *title) :
  title_(title)
{
  LOG(INFO) << "Creating new game: " << title_;
}

const char *Game::title() const
{
  return title_;
}

} // namespace galaxy
