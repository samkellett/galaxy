#include <type_traits>

namespace galaxy {

template <typename Com>
std::shared_ptr<Component> ComponentManager::push()
{
  static_assert(std::is_base_of<Component, Com>(), "Class must be a child of galaxy::Component");

  std::shared_ptr<Com> component(new Com);
  components_.push_back(component);

  return component;
}

template <typename Com, typename P1>
std::shared_ptr<Component> ComponentManager::push(const P1 &p1)
{
  static_assert(std::is_base_of<Component, Com>(), "Class must be a child of galaxy::Component");

  std::shared_ptr<Com> component(new Com(p1));
  components_.push_back(component);

  return component;
}

template <typename Com, typename P1, typename P2>
std::shared_ptr<Component> ComponentManager::push(const P1 &p1, const P2 &p2)
{
  static_assert(std::is_base_of<Component, Com>(), "Class must be a child of galaxy::Component");

  std::shared_ptr<Com> component(new Com(p1, p2));
  components_.push_back(component);

  return component;
}

template <typename Com, typename P1, typename P2, typename P3>
std::shared_ptr<Component> ComponentManager::push(const P1 &p1, const P2 &p2, const P3 &p3)
{
  static_assert(std::is_base_of<Component, Com>(), "Class must be a child of galaxy::Component");

  std::shared_ptr<Com> component(new Com(p1, p2, p3));
  components_.push_back(component);

  return component;
}

} // namespace galaxy
