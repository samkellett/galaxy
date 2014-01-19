#ifndef GALAXY_SCENEMANAGER_H
#define GALAXY_SCENEMANAGER_H

#include <cstdint>
#include <memory>
#include <vector>

#include "scene.h"

namespace galaxy {

class SceneManager
{
public:
  SceneManager();
  ~SceneManager();

  const std::shared_ptr<Scene> current();

  template <typename YourState>
  std::shared_ptr<Scene> push();

  const std::shared_ptr<Scene> at(const uint32_t i);
  const int32_t size();

  const std::shared_ptr<Scene> pop_back();

  const std::shared_ptr<Scene> front();
  const std::shared_ptr<Scene> back();

private:
  int32_t current_;
  std::vector<std::shared_ptr<Scene>> scenes_;
};

} // namespace galaxy

#include "scenemanager.tpp"
#endif
