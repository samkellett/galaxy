#include "objectmanager.h"

#include <yaml-cpp/yaml.h>

#include "game.h"
#include "gameobject.h"

namespace gxy {

void ObjectManager::push(const std::string &name, const YAML::Node &components)
{
  assert(components.IsSequence());
  auto object = std::make_shared<GameObject>(name);
  
  for(const auto &component : components) {
    assert(component.IsMap());

    auto data = component.begin();
    auto name = data->first.as<std::string>();

    auto component_ptr = myGame()->loadComponent(name, data->second);
    object->components().push_back(component_ptr);
  }

  push_back(object);
}

} // namespace gxy

