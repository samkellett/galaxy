#ifndef GALAXY_SCENE_H
#define GALAXY_SCENE_H

#include <chrono>
#include <memory>

#include "objectmanager.h"

namespace galaxy {

class Scene
{
public:
  Scene();
  ~Scene();

  virtual void init() = 0;
  virtual void update(const std::chrono::nanoseconds &dt);
  virtual void render(const std::chrono::nanoseconds &dt);
  virtual void destroy() = 0;

protected:
  const std::shared_ptr<ObjectManager> objects();  

private:
  std::shared_ptr<ObjectManager> objects_;
};

} // namespace galaxy

#endif