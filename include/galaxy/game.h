#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

#include <chrono>
#include <cstdint>
#include <map>
#include <memory>
#include <string>

#include "scenemanager.h"

#define myGame() gxy::Game::instance()
#define myScene() myGame()->scenes().current()

namespace gxy {

class Game
{
public:
  Game(const char *const title, const char *const assets);
  Game(const char *const title, const char *const assets, const uint32_t width, const uint32_t height);
  Game(const Game &) = delete;
  virtual ~Game() = default;
  Game &operator =(Game) = delete;

  static Game *instance();

  const char *const title() const;
  const char *const assets() const;

  const uint32_t width() const;
  const uint32_t height() const;

  SceneManager &scenes();

protected:
  const char *const title_ = "Dark Matter";
  const char *const assets_ = ".";

  const uint32_t width_ = 768;
  const uint32_t height_ = 432;

private:
  static Game *game;

  SceneManager scenes_;
};

} // namespace gxy

#endif // GALAXY_GAME_H