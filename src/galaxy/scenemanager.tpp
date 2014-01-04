#include <cassert>
#include <type_traits>

namespace galaxy {

template <typename YourState>
std::shared_ptr<Scene> SceneManager::push()
{
  static_assert(std::is_base_of<Scene, YourState>(), "Class must be a child of galaxy::Scene");

  const std::shared_ptr<Scene> scene(new YourState);
  scenes_.push_back(scene);

  if (current_ == -1) {
    assert(scenes_.size() == 1);

    current_ = 0;
    scene->init();
  }

  return scene;
}

} // namespace galaxy
