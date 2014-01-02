#ifndef GALAXY_OBJECTMANAGER_H
#define GALAXY_OBJECTMANAGER_H

#include <memory>
#include <vector>

#include "gameobject.h"

namespace galaxy {

class ObjectManager
{
public:
  ObjectManager();
  ~ObjectManager();

  template <typename Obj>
  std::shared_ptr<GameObject> push(const typename Obj::Data &data);

private:
  std::vector<std::shared_ptr<GameObject>> objects_;
};

} // namespace galaxy

#include "objectmanager.tpp"
#endif // GALAXY_OBJECTMANAGER_H
