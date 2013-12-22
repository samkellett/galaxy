#ifndef GALAXY_STATEMANAGER_H
#define GALAXY_STATEMANAGER_H

#include <deque>

namespace galaxy {

class GameState;

class StateManager
{
public:
  StateManager();
  ~StateManager();

  template <typename State>
  void push();

  const std::shared_ptr<GameState> pop_front();
  const std::shared_ptr<GameState> pop_back();

  const std::shared_ptr<GameState> front();
  const std::shared_ptr<GameState> back();

private:
  typedef std::shared_ptr<GameState> GameStatePtr;
  std::deque<GameStatePtr> states_;
};

} // namespace galaxy

#include "statemanager.tpp"
#endif
