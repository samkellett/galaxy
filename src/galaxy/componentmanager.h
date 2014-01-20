#ifndef GALAXY_COMPONENTMANAGER_H
#define GALAXY_COMPONENTMANAGER_H

#include <memory>
#include <vector>

#include "component.h"

namespace glxy {

class ComponentManager
{
public:
  typedef std::shared_ptr<Component> *iterator;
  typedef const std::shared_ptr<Component> *const_iterator;

  ComponentManager();
  ~ComponentManager();

  template <typename Comp, typename... Params>
  std::shared_ptr<Component> push(Params&&... parameters);

  const size_t size() const;

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

private:
  std::vector<std::shared_ptr<Component>> components_;
};

} // namespace glxy

#include "componentmanager.tpp"
#endif // GALAXY_COMPONENTMANAGER_H
