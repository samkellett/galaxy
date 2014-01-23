#ifndef GALAXY_OBJECTMANAGER_H
#define GALAXY_OBJECTMANAGER_H

#include <memory>
#include <vector>

#include "gameobject.h"

namespace gxy {

typedef std::vector<std::shared_ptr<GameObject>> ObjectList;
class ObjectManager : private ObjectList
{
public:
  ObjectManager() = default;

  using ObjectList::begin;
  using ObjectList::end;

  template <typename Obj>
  std::shared_ptr<GameObject> push(const char *const name);
};

} // namespace gxy

#include "objectmanager.tpp"
#endif // GALAXY_OBJECTMANAGER_H
