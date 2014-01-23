#include "game.h"

#include <cassert>
#include <chrono>

#include <glog/logging.h>

namespace gxy {

Game *Game::game = nullptr;

Game::Game(const char *const title, const char *const assets) : Game(title, assets, 640, 480)
{
}

Game::Game(const char *const title, const char *assets, uint32_t width, uint32_t height) :
  title_(title), assets_(assets), width_(width), height_(height)
{
  assert(game == nullptr);
  game = this;

  LOG(INFO) << "Creating new game: " << title_;
}

Game *Game::instance()
{
  assert(game != nullptr);
  return game;
}

const char *const Game::title() const
{
  return title_;
}

const char *const Game::assets() const
{
  return assets_;
}

const uint32_t Game::width() const
{
  return width_;
}

const uint32_t Game::height() const
{
  return height_;
}

SceneManager &Game::scenes()
{
  return scenes_;
}

} // namespace gxy
