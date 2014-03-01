#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

#include <functional>
#include <map>
#include <memory>
#include <string>

#include <boost/filesystem.hpp>

#include "scenemanager.h"

#define myGame() gxy::Game::instance()
#define myScene() myGame()->scenes().current()

namespace YAML { class Node; }

namespace gxy {

class Component;

typedef std::function<std::shared_ptr<Component>(const YAML::Node &)> ComponentLoader;

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

  void registerComponent(const std::string &id, const ComponentLoader &loader);
  std::shared_ptr<Component> loadComponent(const std::string &id, const YAML::Node &d);

  SceneManager &scenes();

protected:
  std::string title_;
  boost::filesystem::path assets_;

  unsigned int width_;
  unsigned int height_;

private:
  static Game *game;

  std::map<std::string, ComponentLoader> loaders_;
  SceneManager scenes_;
};

// Exceptions:

struct component_id_exists : public std::runtime_error
{
  component_id_exists(const std::string &id);
}; 

} // namespace gxy

#endif // GALAXY_GAME_H
