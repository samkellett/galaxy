#ifndef GALAXY_OBJECTMANAGER_H
#define GALAXY_OBJECTMANAGER_H

#include <memory>
#include <string>
#include <vector>

namespace YAML { class Node; }

namespace gxy {

class GameObject;

typedef std::vector<std::shared_ptr<GameObject>> ObjectList;
class ObjectManager final : private ObjectList
{
public:
  ObjectManager() = default;
  ObjectManager(const ObjectManager &) = delete;
  ObjectManager &operator =(ObjectManager) = delete;

  using ObjectList::begin;
  using ObjectList::end;
  using ObjectList::empty;

  void push(const std::string &name, const YAML::Node &components);
};

} // namespace gxy

#endif // GALAXY_OBJECTMANAGER_H
