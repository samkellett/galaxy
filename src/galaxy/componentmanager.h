#ifndef GALAXY_COMPONENTMANAGER_H
#define GALAXY_COMPONENTMANAGER_H

#include <memory>
#include <vector>

#include "component.h"

namespace gxy {

typedef std::vector<std::shared_ptr<Component>> ComponentList;
class ComponentManager : private ComponentList
{
public:
  ComponentManager() = default;

  using ComponentList::size;
  using ComponentList::begin;
  using ComponentList::end;

  template <typename Comp, typename... Params>
  std::shared_ptr<Component> push(Params&&... parameters);
};

} // namespace gxy

#include "componentmanager.tpp"
#endif // GALAXY_COMPONENTMANAGER_H
