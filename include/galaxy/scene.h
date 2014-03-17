#ifndef GALAXY_SCENE_H
#define GALAXY_SCENE_H

#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

#include "fontmanager.h"
#include "objectmanager.h"
#include "shadermanager.h"
#include "mixins/gameable.h"

namespace gxy {

class Component;
class Game;

class Scene : public mixins::Gameable
{
public:
  Scene() = delete;
  Scene(Game &game, const YAML::Node &data);

  virtual ~Scene() = default;
  Scene(const Scene &) = delete;
  Scene &operator =(const Scene &) = delete;

  void init();

  const std::vector<std::shared_ptr<Component>> components();

  FontManager &fonts();
  ObjectManager &objects();
  ShaderManager &shaders();

private:
  const std::string name_;
  const YAML::Node data_;

  FontManager fonts_;
  ShaderManager shaders_;
  ObjectManager objects_;
};

} // namespace gxy

#endif
