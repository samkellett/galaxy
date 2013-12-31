#include "componentmanager.h"

namespace galaxy {

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}

std::vector<std::shared_ptr<Component>>::iterator ComponentManager::begin()
{
  return components_.begin();
}

std::vector<std::shared_ptr<Component>>::iterator ComponentManager::end()
{
  return components_.end();
}

} // namespace galaxy
