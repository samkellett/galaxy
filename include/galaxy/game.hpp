#include <type_traits>

#include <yaml-cpp/yaml.h>

namespace gxy {

template <typename T>
void Game::registerComponent(const std::string &id)
{
  static_assert(std::is_base_of<Component, T>::value, "Cannot register a class that isn't a Component as a component!");
  if (loaders_.count(id)) {
    throw component_id_exists(id);
  }

  loaders_.insert({id, [] (const YAML::Node &node) -> std::shared_ptr<Component> {
    return std::make_shared<T>(node.as<T>());
  }});
}

} // namespace gxy
