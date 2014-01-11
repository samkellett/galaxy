#include <type_traits>

namespace galaxy {

template <typename Comp>
std::shared_ptr<Component> ComponentManager::push(Comp *comp)
{
  static_assert(std::is_base_of<Component, Comp>(), "Class must be a child of galaxy::Component");

  std::shared_ptr<Comp> component(comp);
  components_.push_back(component);

  return component;
}

template <typename Comp>
std::shared_ptr<Component> ComponentManager::push()
{
  return push(new Comp);
}

template <typename Comp, typename P1>
std::shared_ptr<Component> ComponentManager::push(const P1 &p1)
{
  return push(new Comp(p1));
}

template <typename Comp, typename P1, typename P2>
std::shared_ptr<Component> ComponentManager::push(const P1 &p1, const P2 &p2)
{
  return push(new Comp(p1, p2));
}

template <typename Comp, typename P1, typename P2, typename P3>
std::shared_ptr<Component> ComponentManager::push(const P1 &p1, const P2 &p2, const P3 &p3)
{
  return push(new Comp(p1, p2, p3));
}

} // namespace galaxy
