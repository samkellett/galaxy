#ifndef GALAXY_OBJECTMANAGER_H
#define GALAXY_OBJECTMANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "mixins/gameable.h"

namespace YAML { class Node; }

namespace gxy {

class Game;
class GameObject;

typedef std::vector<std::shared_ptr<GameObject>> ObjectList;
class ObjectManager final : private ObjectList, public mixins::Gameable
{
public:
  ObjectManager() = delete;
  ObjectManager(Game &game);
  ObjectManager(const ObjectManager &) = delete;
  ObjectManager &operator =(ObjectManager) = delete;

  using ObjectList::begin;
  using ObjectList::end;
  using ObjectList::empty;

  void push(const YAML::Node &components);
};

} // namespace gxy

#endif // GALAXY_OBJECTMANAGER_H
