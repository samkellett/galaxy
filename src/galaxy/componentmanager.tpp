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

template <typename Com>
std::shared_ptr<Component> ComponentManager::push(const typename Com::Data &data)
{
  static_assert(std::is_base_of<Component, Com>(), "Class must be a child of galaxy::Component");

  std::shared_ptr<Com> component(new Com(data));
  components_.push_back(component);

  return component;
}

} // namespace galaxy
