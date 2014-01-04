#include "scene.h"

#include <cassert>
#include <glog/logging.h>

#include "component.h"

namespace galaxy {

Scene::Scene() : 
  objects_(new ObjectManager)
{
}

Scene::~Scene()
{ 
}

const std::vector<std::shared_ptr<Component>> Scene::components()
{
  std::vector<std::shared_ptr<Component>> components;
  for (std::shared_ptr<GameObject> object : *objects()) {
    assert(object);
    assert(object->components());

    std::vector<std::shared_ptr<Component>> tmp;
    tmp.reserve(components.size() + object->components()->size());

    std::merge(components.begin(), components.end(), object->components()->begin(), object->components()->end(), std::back_inserter(tmp));
    components.swap(tmp);
  }

  return components;
}

const std::shared_ptr<ObjectManager> Scene::objects()
{
  return objects_;
}

} // namespace galaxy
