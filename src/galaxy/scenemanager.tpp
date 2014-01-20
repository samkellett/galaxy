#include <cassert>
#include <type_traits>

namespace glxy {

template <typename YourState>
std::shared_ptr<Scene> SceneManager::push()
{
  static_assert(std::is_base_of<Scene, YourState>(), "Class must be a child of galaxy::Scene");

  const std::shared_ptr<Scene> scene(new YourState);
  scenes_.push_back(scene);

  return scene;
}

} // namespace glxy
