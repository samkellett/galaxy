#ifndef GALAXY_SCENE_H
#define GALAXY_SCENE_H

#include <chrono>
#include <memory>
#include <vector>

#include "fontmanager.h"
#include "objectmanager.h"

namespace galaxy {

class Component;

class Scene
{
public:
  Scene();
  ~Scene();

  virtual void init() = 0;

  const std::vector<std::shared_ptr<Component>> components();

protected:
  FontManager &fonts();
  ObjectManager &objects();

private:
  FontManager fonts_;
  // ShaderManager shaders_;
  ObjectManager objects_;
};

} // namespace galaxy

#endif
