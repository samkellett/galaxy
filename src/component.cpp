#include "component.h"

#include <yaml-cpp/yaml.h>

#include "game.h"
#include "logger.h"

namespace gxy {

void Component::setTypeAndName(const std::string &type, const std::string &name)
{
  type_ = type;
  name_ = name;
}

const std::string &Component::type() const
{
  return type_;
}

const std::string &Component::name() const
{
  return name_;
}

std::shared_ptr<Component> load_component(const std::shared_ptr<Game> game, const YAML::Node &data)
{
  assert(data.IsMap());
  auto type = data["type"].as<std::string>();
  auto name = data["name"] ? data["name"].as<std::string>() : type;

  LOG(INFO) << "Adding component: " << name << ", of type: " << type;

  std::shared_ptr<Component> component = game->component(type)(data);
  component->setTypeAndName(type, name);
  component->setGame(game);

  return component;
}

} // namespace gxy
