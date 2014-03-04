#ifndef GALAXY_SCENEMANAGER_H
#define GALAXY_SCENEMANAGER_H

#include <cstdint>
#include <memory>
#include <vector>

#include "mixins/gameable.h"

namespace YAML { class Node; }

namespace gxy {

class Game;
class Scene;

typedef std::vector<std::shared_ptr<Scene>> SceneList;

class SceneManager final : private SceneList, public mixins::Gameable
{
public:
  SceneManager() = delete;
  SceneManager(const std::shared_ptr<Game> game);
  SceneManager(const SceneManager &) = delete;
  SceneManager &operator =(SceneManager) = delete;

  void operator <<(const YAML::Node &scenes);

  using SceneList::empty;
  using SceneList::front;

  const std::shared_ptr<Scene> current();
  const std::shared_ptr<Scene> next();

private:
  int current_ = -1;
};

} // namespace gxy

#endif
