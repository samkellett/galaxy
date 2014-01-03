#include <type_traits>

namespace galaxy {

template <typename State>
std::shared_ptr<Scene> StateManager::push()
{
  static_assert(std::is_base_of<Scene, State>(), "Class must be a child of galaxy::Scene");

  const std::shared_ptr<Scene> state(new State);
  states_.push_back(state);

  state->init();
  return state;
}

} // namespace galaxy
