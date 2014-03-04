#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

#include <functional>
#include <map>
#include <memory>
#include <string>

#include <boost/filesystem.hpp>

#include "scenemanager.h"

namespace YAML { class Node; }

namespace gxy {

class Component;

class Game : public std::enable_shared_from_this<Game>
{
public:
  Game(const boost::filesystem::path &config);
  Game(const Game &) = delete;
  virtual ~Game() = default;
  Game &operator =(Game) = delete;

  void init();

  const std::string &title() const;
  const boost::filesystem::path &assets() const;

  unsigned int width() const;
  unsigned int height() const;

  template <typename T>
  void registerComponent(const std::string &id);
  std::shared_ptr<Component> loadComponent(const std::string &id, const YAML::Node &d);

  SceneManager &scenes();

private:
  boost::filesystem::path config_;

  std::string title_;
  boost::filesystem::path assets_;

  unsigned int width_;
  unsigned int height_;

  typedef std::function<std::shared_ptr<Component>(const YAML::Node &)> ComponentLoader;
  std::map<std::string, ComponentLoader> loaders_;
  SceneManager scenes_;
};

// Exceptions:

struct component_id_exists : public std::runtime_error
{
  component_id_exists(const std::string &id);
};

} // namespace gxy

#include "game.hpp"
#endif // GALAXY_GAME_H

