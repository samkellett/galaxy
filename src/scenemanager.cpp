#include "scenemanager.h"

#include <cassert>

#include "scene.h"

namespace gxy {

const std::shared_ptr<Scene> SceneManager::current()
{
  if (current_ >= 0 || current_ < size()) {
    return at(current_);
  } else {
    return nullptr;
  }
}

const std::shared_ptr<Scene> SceneManager::next()
{
  ++current_;
  assert(current_ >= 0);

  if (current_ < size()) {
    return at(current_);
  } else {
    return nullptr;
  }
}

} // namespace gxy
