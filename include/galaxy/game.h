#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

#include <string>

#include <boost/filesystem.hpp>

#include "scenemanager.h"

#define myGame() gxy::Game::instance()
#define myScene() myGame()->scenes().current()

namespace gxy {

class Game
{
public:
  Game(const std::string &config);
  Game(const Game &) = delete;
  virtual ~Game() = default;
  Game &operator =(Game) = delete;

  static Game *instance();

  const std::string &title() const;
  const boost::filesystem::path &assets() const;

  const unsigned int width() const;
  const unsigned int height() const;

  SceneManager &scenes();

protected:
  std::string title_;
  boost::filesystem::path assets_;

  unsigned int width_;
  unsigned int height_;

private:
  static Game *game;

  SceneManager scenes_;
};

} // namespace gxy

#endif // GALAXY_GAME_H
