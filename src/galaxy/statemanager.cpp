#include "statemanager.h"

#include <cassert>

namespace galaxy {

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

const std::shared_ptr<GameState> StateManager::at(int32_t i)
{
  return states_.at(i);
}

const int32_t StateManager::size()
{
  return states_.size();
}

const std::shared_ptr<GameState> StateManager::pop_front()
{
  assert(!states_.empty());
  const auto front = states_.front();
  states_.pop_front();

  return front;
}

const std::shared_ptr<GameState> StateManager::pop_back()
{
  assert(!states_.empty());
  const auto back = states_.back();
  states_.pop_back();

  return back;
}

const std::shared_ptr<GameState> StateManager::front()
{
  assert(!states_.empty());
  return states_.front();
}

const std::shared_ptr<GameState> StateManager::back()
{
  assert(!states_.empty());
  return states_.back();
}

} // namespace galaxy
