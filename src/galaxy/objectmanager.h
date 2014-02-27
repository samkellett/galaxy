#ifndef GALAXY_OBJECTMANAGER_H
#define GALAXY_OBJECTMANAGER_H

#include <memory>
#include <vector>

#include "gameobject.h"

namespace gxy {

typedef std::vector<std::shared_ptr<GameObject>> ObjectList;
class ObjectManager final : private ObjectList
{
public:
  ObjectManager() = default;
  ObjectManager(const ObjectManager &) = delete;
  ObjectManager &operator =(ObjectManager) = delete;

  using ObjectList::begin;
  using ObjectList::end;

  template <typename Obj>
  std::shared_ptr<GameObject> push(const char *const name);
};

} // namespace gxy

#include "objectmanager.hpp"
#endif // GALAXY_OBJECTMANAGER_H
