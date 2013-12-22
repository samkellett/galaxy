#include "statemanager.h"

namespace galaxy {

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

const std::shared_ptr<GameState> StateManager::pop_front()
{
  assert(!states_.empty());
  const std::shared_ptr<GameState> front = states_.front();
  states_.pop_front();

  return front;
}

const std::shared_ptr<GameState> StateManager::pop_back()
{
  assert(!states_.empty());
  const std::shared_ptr<GameState> back = states_.back();
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