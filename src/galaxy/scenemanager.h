#ifndef GALAXY_SCENEMANAGER_H
#define GALAXY_SCENEMANAGER_H

#include <cstdint>
#include <memory>
#include <vector>

#include "scene.h"

namespace glxy {

class SceneManager
{
public:
  SceneManager();
  ~SceneManager();

  const std::shared_ptr<Scene> current();

  template <typename YourState>
  std::shared_ptr<Scene> push();

  const std::shared_ptr<Scene> next();

private:
  int32_t current_;
  std::vector<std::shared_ptr<Scene>> scenes_;
};

} // namespace glxy

#include "scenemanager.tpp"
#endif
