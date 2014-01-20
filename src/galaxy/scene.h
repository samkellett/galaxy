#ifndef GALAXY_SCENE_H
#define GALAXY_SCENE_H

#include <chrono>
#include <memory>
#include <vector>

#include "fontmanager.h"
#include "objectmanager.h"
#include "shadermanager.h"

namespace glxy {

class Component;

class Scene
{
public:
  Scene();
  ~Scene();

  virtual void init() = 0;

  const std::vector<std::shared_ptr<Component>> components();

  FontManager &fonts();
  ObjectManager &objects();
  ShaderManager &shaders();

private:
  FontManager fonts_;
  ShaderManager shaders_;
  ObjectManager objects_;
};

} // namespace glxy

#endif
