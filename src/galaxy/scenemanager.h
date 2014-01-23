#ifndef GALAXY_SCENEMANAGER_H
#define GALAXY_SCENEMANAGER_H

#include <cstdint>
#include <memory>
#include <vector>

#include "scene.h"

namespace gxy {

typedef std::vector<std::shared_ptr<Scene>> SceneList;
class SceneManager : public SceneList
{
public:
  SceneManager() = default;

  const std::shared_ptr<Scene> current();

  template <typename YourState>
  std::shared_ptr<Scene> push();

  const std::shared_ptr<Scene> next();

private:
  int32_t current_ = -1;
};

} // namespace gxy

#include "scenemanager.tpp"
#endif
