#include "scene.h"

#include <algorithm>
#include <cassert>

#include <boost/filesystem.hpp>
#include <glog/logging.h>

#include "component.h"
#include "gameobject.h"

namespace gxy {

Scene::Scene(const std::string &name, const YAML::Node &data) :
  name_(name), data_(data)
{
}

void Scene::init()
{
  assert(fonts_.empty());
  assert(shaders_.empty());
  assert(objects_.empty());

  LOG(INFO) << "Scene: " << name_; 
  assert(data_["objects"] && data_["objects"].IsSequence());

  if (data_["fonts"]) {
    assert(data_["fonts"].IsSequence());
 
    LOG(INFO) << "Loading fonts...";
    for(const auto &font : data_["fonts"]) {
      auto name = font["name"].as<std::string>();
      boost::filesystem::path path(font["path"].as<std::string>());

      LOG(INFO) << "Loading font: " << name << ", at: " << path;
      fonts_.push(name, path);
    }
  }
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
