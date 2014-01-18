#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

#include <chrono>
#include <cstdint>
#include <map>
#include <memory>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "scenemanager.h"

#define myGame() galaxy::Game::instance()

namespace galaxy {

class Game
{
public:
  Game();
  Game(const char *const title, const char *const assets);
  Game(const char *const title, const char *const assets, const uint32_t width, const uint32_t height);

  static Game *instance();

  const char *const title() const;
  const char *const assets() const;

  const uint32_t width() const;
  const uint32_t height() const;

  const std::shared_ptr<Scene> currentScene();
  SceneManager &scenes();

  std::map<const char *const, std::shared_ptr<FT_Face>> &fonts();
  void addFont(const std::string &font);

protected:
  const char *const title_;
  const char *const assets_;

  const uint32_t width_;
  const uint32_t height_;

private:
  static Game *game;

  SceneManager scenes_;

  FT_Library freetype_;
  std::map<const char *const, std::shared_ptr<FT_Face>> fonts_;
};

} // namespace galaxy

#endif // GALAXY_GAME_H
