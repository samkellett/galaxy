#ifndef GALAXY_SCENEMANAGER_H
#define GALAXY_SCENEMANAGER_H

#include <cstdint>
#include <memory>
#include <vector>

namespace gxy {

class Scene;

typedef std::vector<std::shared_ptr<Scene>> SceneList;
class SceneManager final : private SceneList
{
public:
  SceneManager() = default;
  SceneManager(const SceneManager &) = delete;
  SceneManager &operator =(SceneManager) = delete;

  const std::shared_ptr<Scene> current();

  template <typename YourState>
  std::shared_ptr<Scene> push();

  const std::shared_ptr<Scene> next();

private:
  int32_t current_ = -1;
};

} // namespace gxy

#include "scenemanager.hpp"
#endif
