#include "objectmanager.h"

namespace glxy {

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

ObjectManager::iterator ObjectManager::begin()
{
  return &objects_[0];
}

ObjectManager::const_iterator ObjectManager::begin() const
{
  return &objects_[0];
}

ObjectManager::iterator ObjectManager::end()
{
  return &objects_[objects_.size()];
}

ObjectManager::const_iterator ObjectManager::end() const
{
  return &objects_[objects_.size()];
}

} // namespace glxy
