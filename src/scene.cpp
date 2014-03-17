#include "scene.h"

#include <algorithm>
#include <cassert>

#include <boost/filesystem.hpp>
#include <glog/logging.h>

#include "component.h"
#include "game.h"
#include "gameobject.h"
#include "shadertype.h"

namespace {

template <typename Manager>
void load_data(const char *key, const YAML::Node &data, Manager &manager)
{
  if (data[key]) {
    assert(data[key].IsSequence());

    LOG(INFO) << "Loading " << key << "...";
    for(const auto &node : data[key]) {
      manager.push(node);
    }
  }
}

} // unnamed namespace

namespace gxy {

Scene::Scene(Game &g, const YAML::Node &data) : mixins::Gameable(g),
  name_(data["name"].as<std::string>()),
  data_(data),
  fonts_(game()),
  shaders_(game()),
  objects_(game())
{
}

void Scene::init()
{
  assert(fonts_.empty());
  assert(shaders_.empty());
  assert(objects_.empty());

  LOG(INFO) << "Initialising scene: " << name_;
  load_data("fonts", data_, fonts_);
  load_data("shaders", data_, shaders_);

  assert(data_["objects"]);
  load_data("objects", data_, objects_);
}

const std::vector<std::shared_ptr<Component>> Scene::components()
{
  std::vector<std::shared_ptr<Component>> components;
  for (std::shared_ptr<GameObject> object : objects()) {
    assert(object);

    std::vector<std::shared_ptr<Component>> tmp;
    tmp.reserve(components.size() + object->components().size());

    std::merge(components.begin(), components.end(), object->components().begin(), object->components().end(), std::back_inserter(tmp));
    components.swap(tmp);
  }

  return components;
}

FontManager &Scene::fonts()
{
  return fonts_;
}

ObjectManager &Scene::objects()
{
  return objects_;
}

ShaderManager &Scene::shaders()
{
  return shaders_;
}

} // namespace gxy
