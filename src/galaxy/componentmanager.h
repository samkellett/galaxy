#ifndef GALAXY_COMPONENTMANAGER_H
#define GALAXY_COMPONENTMANAGER_H

#include <memory>
#include <vector>

namespace gxy {

class Component;

typedef std::vector<std::shared_ptr<Component>> ComponentList;
class ComponentManager final : private ComponentList
{
public:
  ComponentManager() = default;
  ComponentManager(const ComponentManager &) = delete;
  ComponentManager &operator =(ComponentManager) = delete;

  using ComponentList::size;
  using ComponentList::begin;
  using ComponentList::end;

  template <typename Comp, typename... Params>
  std::shared_ptr<Component> push(Params&&... parameters);
};

} // namespace gxy

#include "componentmanager.hpp"
#endif // GALAXY_COMPONENTMANAGER_H
