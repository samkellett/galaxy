#include "scenemanager.h"

#include <cassert>

#include <yaml-cpp/yaml.h>

#include "game.h"
#include "logger.h"
#include "scene.h"

namespace gxy {

SceneManager::SceneManager() : mixins::Gameable()
{
}

void SceneManager::operator <<(const YAML::Node &scenes)
{
  assert(scenes.IsSequence());

  for(const auto &scene : scenes) {
    assert(scene.IsMap());

    auto key = scene.begin();
    auto scene_ptr = std::make_shared<Scene>(game(), key->first.as<std::string>(), key->second);
    push_back(scene_ptr);
  }
}

const std::shared_ptr<Scene> SceneManager::current()
{
  if (current_ >= 0 || current_ < static_cast<int>(size())) {
    return at(current_);
  } else {
    return nullptr;
  }
}

const std::shared_ptr<Scene> SceneManager::next()
{
  ++current_;
  assert(current_ >= 0);

  if (current_ < static_cast<int>(size())) {
    return at(current_);
  } else {
    return nullptr;
  }
}

} // namespace gxy
