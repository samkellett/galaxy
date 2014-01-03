#include "scene.h"

namespace galaxy {

Scene::Scene() : 
  objects_(new ObjectManager)
{
}

Scene::~Scene()
{ 
}

void Scene::update(const std::chrono::nanoseconds &dt)
{
}

void Scene::render(const std::chrono::nanoseconds &dt)
{
}

const std::shared_ptr<ObjectManager> Scene::objects()
{
  return objects_;
}

} // namespace galaxy
