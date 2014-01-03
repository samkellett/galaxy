#include "statemanager.h"

#include <cassert>

#include "scene.h"

namespace galaxy {

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

const std::shared_ptr<Scene> StateManager::at(int32_t i)
{
  return states_.at(i);
}

const int32_t StateManager::size()
{
  return states_.size();
}

const std::shared_ptr<Scene> StateManager::pop_back()
{
  assert(!states_.empty());
  const auto back = states_.back();
  states_.pop_back();

  return back;
}

const std::shared_ptr<Scene> StateManager::front()
{
  assert(!states_.empty());
  return states_.front();
}

const std::shared_ptr<Scene> StateManager::back()
{
  assert(!states_.empty());
  return states_.back();
}

} // namespace galaxy
