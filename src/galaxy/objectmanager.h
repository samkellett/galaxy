#ifndef GALAXY_OBJECTMANAGER_H
#define GALAXY_OBJECTMANAGER_H

#include <memory>
#include <vector>

#include "gameobject.h"

namespace galaxy {

class ObjectManager
{
public:
  typedef std::shared_ptr<GameObject> *iterator;
  typedef const std::shared_ptr<GameObject> *const_iterator;

  ObjectManager();
  ~ObjectManager();

  template <typename Obj>
  std::shared_ptr<GameObject> push();

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

private:
  std::vector<std::shared_ptr<GameObject>> objects_;
};

} // namespace galaxy

#include "objectmanager.tpp"
#endif // GALAXY_OBJECTMANAGER_H
