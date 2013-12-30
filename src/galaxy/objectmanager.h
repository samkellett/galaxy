#ifndef GALAXY_OBJECTMANAGER_H
#define GALAXY_OBJECTMANAGER_H

#include <vector>

#include "gameobject.h"

namespace galaxy {

class ObjectManager
{
public:
  ObjectManager();
  ~ObjectManager();

  template <typename Obj>
  void push(const typename Obj::Data &data);

private:
  std::vector<std::shared_ptr<GameObject>> objects_;
};

} // namespace galaxy

#include "objectmanager.tpp"
#endif // GALAXY_OBJECTMANAGER_H