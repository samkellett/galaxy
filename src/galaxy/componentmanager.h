#ifndef GALAXY_COMPONENTMANAGER_H
#define GALAXY_COMPONENTMANAGER_H

#include <memory>
#include <vector>

#include "component.h"

namespace galaxy {

class ComponentManager
{
public:
  typedef std::shared_ptr<Component> *iterator;
  typedef const std::shared_ptr<Component> *const_iterator;

  ComponentManager();
  ~ComponentManager();

  template <typename Comp> 
  std::shared_ptr<Component> push();

  template <typename Comp, typename P1>
  std::shared_ptr<Component> push(const P1 &p1);

  template <typename Comp, typename P1, typename P2>
  std::shared_ptr<Component> push(const P1 &p1, const P2 &p2);

  template <typename Comp, typename P1, typename P2, typename P3>
  std::shared_ptr<Component> push(const P1 &p1, const P2 &p2, const P3 &p3);

  const size_t size() const;

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

private:
  std::vector<std::shared_ptr<Component>> components_;
};

} // namespace galaxy

#include "componentmanager.tpp"
#endif // GALAXY_COMPONENTMANAGER_H
