#ifndef GALAXY_COMPONENTMANAGER_H
#define GALAXY_COMPONENTMANAGER_H

#include <vector>

#include "component.h"

namespace galaxy {

class ComponentManager
{
public:
  ComponentManager();
  ~ComponentManager();

  template <typename Comp>
  std::shared_ptr<Component> push();

  std::vector<std::shared_ptr<Component>>::iterator begin();
  std::vector<std::shared_ptr<Component>>::iterator end();

private:
  std::vector<std::shared_ptr<Component>> components_;
};

} // namespace galaxy

#include "componentmanager.tpp"
#endif // GALAXY_COMPONENTMANAGER_H
