#ifndef GALAXY_COMPONENTMANAGER_H
#define GALAXY_COMPONENTMANAGER_H

#include <memory>
#include <vector>

#include "mixins/gameable.h"

namespace gxy {

class Component;
class Game;

typedef std::vector<std::shared_ptr<Component>> ComponentList;

class ComponentManager final : private ComponentList, public mixins::Gameable
{
public:
  ComponentManager() = delete;
  ComponentManager(Game &game);
  ComponentManager(const ComponentManager &) = delete;
  ComponentManager &operator =(ComponentManager) = delete;

  using ComponentList::size;
  using ComponentList::begin;
  using ComponentList::end;
  using ComponentList::push_back;
};

} // namespace gxy

#endif // GALAXY_COMPONENTMANAGER_H
