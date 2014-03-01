#include "scenemanager.h"

#include <cassert>

#include <yaml-cpp/yaml.h>

#include "logger.h"
#include "scene.h"

namespace gxy {

void SceneManager::operator <<(const YAML::Node &scenes)
{
  assert(scenes.IsSequence());

  for(const auto &scene : scenes) {
    assert(scene.IsMap());

    auto key = scene.begin();
    auto scene_ptr = std::make_shared<Scene>(key->first.as<std::string>(), key->second);
    push_back(scene_ptr);
  }
}

const std::shared_ptr<Scene> SceneManager::current()
{
  if (current_ >= 0 || current_ < size()) {
    return at(current_);
  } else {
    return nullptr;
  }
}

const std::shared_ptr<Scene> SceneManager::next()
{
  ++current_;
  assert(current_ >= 0);

  if (current_ < size()) {
    return at(current_);
  } else {
    return nullptr;
  }
}

} // namespace gxy
