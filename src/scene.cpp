#include "scene.h"

#include <algorithm>
#include <cassert>

#include <boost/filesystem.hpp>
#include <glog/logging.h>

#include "component.h"
#include "gameobject.h"
#include "shadertype.h"

namespace gxy {

Scene::Scene(const std::shared_ptr<Game> g, const std::string &name, const YAML::Node &data) : mixins::Gameable(g),
  name_(name),
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

  LOG(INFO) << "Scene: " << name_;
  if (data_["fonts"]) {
    assert(data_["fonts"].IsSequence());

    LOG(INFO) << "Loading fonts...";
    for(const auto &font : data_["fonts"]) {
      auto name = font["name"].as<std::string>();
      boost::filesystem::path path(font["path"].as<std::string>());

      LOG(INFO) << " - Font: " << name << ", at: " << path;
      fonts_.push(name, path);
    }
  }

  if (data_["shaders"]) {
    assert(data_["shaders"].IsSequence());

    LOG(INFO) << "Loading shaders...";
    for (const auto &shader : data_["shaders"]) {
      auto name = shader["name"].as<std::string>();
      boost::filesystem::path path(shader["path"].as<std::string>());
      auto type = shader["type"].as<ShaderType>();

      LOG(INFO) << " - Shader: " << name << " (" << shader["type"].as<std::string>() << "), at: " << path;
      shaders_.push(name, path, type);
    }
  }

  assert(data_["objects"] && data_["objects"].IsSequence());
  LOG(INFO) << "Loading objects...";
  for (const auto &object : data_["objects"]) {
    assert(object.IsMap());

    auto data = object.begin();
    auto name = data->first.as<std::string>();

    LOG(INFO) << " - Object: " << name;
    objects_.push(name, data->second);
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
