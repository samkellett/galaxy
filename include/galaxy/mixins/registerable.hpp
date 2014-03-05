#include <yaml-cpp/yaml.h>

namespace gxy {
namespace mixins {

template <typename T>
std::shared_ptr<Component> Registerable<T>::registerComponent(const std::string &type, const std::string &name, const YAML::Node &node)
{
  std::shared_ptr<T> component = std::make_shared<T>(node.as<T>());
  component->setTypeAndName(type, name);

  return component;
}

} // namespace mixins
} // namespace gxy
