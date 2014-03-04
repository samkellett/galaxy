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
  ObjectManager(const std::shared_ptr<Game> game);
  ObjectManager(const ObjectManager &) = delete;
  ObjectManager &operator =(ObjectManager) = delete;

  using ObjectList::begin;
  using ObjectList::end;
  using ObjectList::empty;

  void push(const std::string &name, const YAML::Node &components);
};

} // namespace gxy

#endif // GALAXY_OBJECTMANAGER_H
