#include "componentmanager.h"

namespace glxy {

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}

const size_t ComponentManager::size() const
{
  return components_.size();
}

ComponentManager::iterator ComponentManager::begin()
{
  return &components_[0];
}

ComponentManager::const_iterator ComponentManager::begin() const
{
  return &components_[0];
}

ComponentManager::iterator ComponentManager::end()
{
  return &components_[components_.size()];
}

ComponentManager::const_iterator ComponentManager::end() const
{
  return &components_[components_.size()];
}

} // namespace glxy
