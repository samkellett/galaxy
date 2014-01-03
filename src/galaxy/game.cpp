#include "game.h"

#include <cassert>
#include <chrono>
#include <glog/logging.h>

namespace galaxy {

Game::Game() : Game("Dark Matter", 640, 480)
{
}

Game::Game(const char *const title) : Game(title, 640, 480)
{
}

Game::Game(const char *const title, uint32_t width, uint32_t height) :
  title_(title), width_(width), height_(height), scenes_(new SceneManager)
{
  LOG(INFO) << "Creating new game: " << title_;
}

const char *const Game::title() const
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

void Game::update(const std::chrono::nanoseconds &dt)
{
  for (int32_t i = 0; i < scenes()->size(); ++i) {
  	auto state = scenes()->at(i);
  	assert(state);

  	state->update(dt);
  }
}

void Game::render(const std::chrono::nanoseconds &dt)
{
  for (int32_t i = 0; i < scenes()->size(); ++i) {
  	auto state = scenes()->at(i);
  	assert(state);

  	state->render(dt);
  }
}

const std::shared_ptr<SceneManager> Game::scenes() const
{
  return scenes_;
}

} // namespace galaxy
