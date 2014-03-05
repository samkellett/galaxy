#include <type_traits>

#include "mixins/registerable.h"

namespace gxy {

template <typename T>
void Game::registerComponent(const std::string &id)
{
  static_assert(std::is_base_of<mixins::Registerable<T>, T>::value, "Cannot register a non-Registerable component.");
  if (loaders_.count(id)) {
    throw component_id_exists(id);
  }

  // TODO: &YAML::Node::as<T>
  loaders_.insert({id, &T::registerComponent});
}

} // namespace gxy
