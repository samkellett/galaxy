#include <type_traits>

#include "gamestate.h"

namespace galaxy {

template <typename State>
std::shared_ptr<GameState> StateManager::push()
{
  static_assert(std::is_base_of<GameState, State>(), "Class must be a child of galaxy::GameState");

  const std::shared_ptr<GameState> state(new State);
  states_.push_front(state);

  state->init();
  return state;
}

} // namespace galaxy
