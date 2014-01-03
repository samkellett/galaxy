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

  template <typename YourState>
  std::shared_ptr<Scene> push();

  const std::shared_ptr<Scene> at(const int32_t i);
  const int32_t size();

  const std::shared_ptr<Scene> pop_back();

  const std::shared_ptr<Scene> front();
  const std::shared_ptr<Scene> back();

private:
  std::vector<std::shared_ptr<Scene>> scenes_;
};

} // namespace galaxy

#include "scenemanager.tpp"
#endif
