#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

#include <chrono>
#include <cstdint>
#include <memory>

#include "scenemanager.h"

namespace galaxy {

class Game
{
public:
  Game();
  Game(const char *const title, const char *const assets);
  Game(const char *const title, const char *const assets, const uint32_t width, const uint32_t height);

  const char *const title() const;
  const uint32_t width() const;
  const uint32_t height() const;

  const std::shared_ptr<Scene> currentScene() const;

protected:
  const std::shared_ptr<SceneManager> scenes() const;

  const char *const title_;
  const char *const assets_;

  const uint32_t width_;
  const uint32_t height_;

private:
  std::shared_ptr<SceneManager> scenes_;
};

} // namespace galaxy

#endif // GALAXY_GAME_H
