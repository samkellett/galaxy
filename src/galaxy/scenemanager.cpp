#include "scenemanager.h"

#include <cassert>

#include "scene.h"

namespace galaxy {

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

const std::shared_ptr<Scene> SceneManager::at(const int32_t i)
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
