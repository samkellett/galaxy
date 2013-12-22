#include <type_traits>

namespace galaxy {

template <typename State>
void StateManager::push()
{
  static_assert(std::is_base_of<GameState, State>(), "Class must be a child of galaxy::GameState");

  const std::shared_ptr<GameState> state(new State);
  states_.push_front(state);
}

} // namespace galaxy
