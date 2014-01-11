#ifndef GALAXY_SCENE_H
#define GALAXY_SCENE_H

#include <chrono>
#include <memory>
#include <vector>

#include "objectmanager.h"

namespace galaxy {

class Component;

class Scene
{
public:
  Scene();
  ~Scene();

  virtual void init() = 0;
  virtual void destroy() = 0;

  const std::vector<std::shared_ptr<Component>> components();

protected:
  ObjectManager &objects();  

private:
  ObjectManager objects_;
};

} // namespace galaxy

#endif
