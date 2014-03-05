#include "objectmanager.h"

#include <yaml-cpp/yaml.h>

#include "component.h"
#include "game.h"
#include "gameobject.h"
#include "logger.h"

namespace gxy {

ObjectManager::ObjectManager(const std::shared_ptr<Game> game) : mixins::Gameable(game)
{
}

void ObjectManager::push(const YAML::Node &data)
{
  assert(data.IsMap());
  auto name = data["name"].as<std::string>();

  LOG(INFO) << "Adding object: " << name;
  auto object = std::make_shared<GameObject>(game(), name);

  LOG(INFO) << "Loading components...";
  for(const auto &component : data["components"]) {
    auto component_ptr = load_component(game(), component);
    object->components().push_back(component_ptr);
  }

  push_back(object);
}

} // namespace gxy

