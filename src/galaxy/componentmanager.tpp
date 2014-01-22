#include <type_traits>
#include <utility>

namespace gxy {

template <typename Comp, typename... Params>
std::shared_ptr<Component> ComponentManager::push(Params&&... params)
{
  static_assert(std::is_base_of<Component, Comp>(), "Class must be a child of galaxy::Component");

  std::shared_ptr<Comp> component(new Comp(std::forward<Params>(params)...));
  components_.push_back(component);

  return component;
}

} // namespace gxy
