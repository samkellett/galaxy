#ifndef GALAXY_SCENEMANAGER_H
#define GALAXY_SCENEMANAGER_H

#include <cstdint>
#include <memory>
#include <vector>

namespace YAML { class Node; }

namespace gxy {

class Scene;

typedef std::vector<std::shared_ptr<Scene>> SceneList;

class SceneManager final : private SceneList
{
public:
  SceneManager() = default;
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
