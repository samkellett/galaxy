#include <yaml-cpp/yaml.h>

namespace gxy {
namespace mixins {

template <typename T>
std::shared_ptr<Component> Registerable<T>::registerComponent(const YAML::Node &node)
{
  return std::make_shared<T>(node.as<T>());
}

} // namespace mixins
} // namespace gxy
