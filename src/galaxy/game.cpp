#include "game.h"

#include <cassert>
#include <chrono>
#include <glog/logging.h>

namespace galaxy {

Game *Game::game = nullptr;

Game::Game() : Game("Dark Matter", ".", 640, 480)
{
}

Game::Game(const char *const title, const char *const assets) : Game(title, assets, 640, 480)
{
}

Game::Game(const char *const title, const char *assets, uint32_t width, uint32_t height) :
  title_(title), assets_(assets), width_(width), height_(height), scenes_(new SceneManager)
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

const std::shared_ptr<Scene> Game::currentScene() const
{
  return scenes_->current();
}

const std::shared_ptr<SceneManager> Game::scenes() const
{
  return scenes_;
}

} // namespace galaxy
