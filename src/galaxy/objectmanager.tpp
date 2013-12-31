#include <type_traits>

namespace galaxy {

template <typename Obj>
std::shared_ptr<GameObject> ObjectManager::push(const typename Obj::Data &data)
{
  static_assert(std::is_base_of<GameObject, Obj>(), "Class must be a child of galaxy::GameObject");

  std::shared_ptr<GameObject> object = std::shared_ptr<GameObject>(new Obj(data));
  objects_.push_back(object);

  return object;
}

} // namespace galaxy
