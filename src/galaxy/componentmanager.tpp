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

template <typename Comp, typename... Params>
std::shared_ptr<Component> ComponentManager::push(const Params&... params)
{
  return push(new Comp(params...));
}

} // namespace galaxy
