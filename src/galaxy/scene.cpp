#include "scene.h"

namespace galaxy {

Scene::Scene() : 
  objects_(new ObjectManager)
{
}

Scene::~Scene()
{ 
}

const std::shared_ptr<ObjectManager> Scene::objects()
{
  return objects_;
}

} // namespace galaxy
