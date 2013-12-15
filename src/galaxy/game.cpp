#include "game.h"

namespace galaxy {

Game::Game() : Game("Dark Matter", 640, 480)
{
}

Game::Game(const char * const title) : Game(title, 640, 480)
{
}

Game::Game(const char * const title, uint32_t width, uint32_t height) :
  title_(title), width_(width), height_(height)
{
  LOG(INFO) << "Creating new game: " << title_;
}

const char * const Game::title() const
{
  return title_;
}

const uint32_t Game::width() const
{
  return width_;
}

const uint32_t Game::height() const
{
  return height_;
}

} // namespace galaxy
