#include "scenemanager.h"

#include <cassert>

#include "scene.h"

namespace gxy {

SceneManager::SceneManager() :
  current_(-1)
{
}

SceneManager::~SceneManager()
{
}

const std::shared_ptr<Scene> SceneManager::current()
{
  if (current_ >= 0 || current_ < scenes_.size()) {
    return scenes_.at(current_);
  } else {
    return nullptr;
  }
}

const std::shared_ptr<Scene> SceneManager::next()
{
  ++current_;
  assert(current_ >= 0);

  if (current_ < scenes_.size()) {
    return scenes_.at(current_);
  } else {
    return nullptr;
  }
}

} // namespace gxy
