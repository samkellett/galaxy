#include "scenemanager.h"

#include <cassert>

#include "scene.h"

namespace galaxy {

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
    return at(current_);
  } else {
    return nullptr;
  }
}

const std::shared_ptr<Scene> SceneManager::at(const uint32_t i)
{
  return scenes_.at(i);
}

const int32_t SceneManager::size()
{
  return scenes_.size();
}

const std::shared_ptr<Scene> SceneManager::pop_back()
{
  assert(!scenes_.empty());
  const auto back = scenes_.back();
  scenes_.pop_back();

  return back;
}

const std::shared_ptr<Scene> SceneManager::front()
{
  assert(!scenes_.empty());
  return scenes_.front();
}

const std::shared_ptr<Scene> SceneManager::back()
{
  assert(!scenes_.empty());
  return scenes_.back();
}

} // namespace galaxy
