#ifndef GALAXY_GAMEOBJECT_H
#define GALAXY_GAMEOBJECT_H

#include <chrono>
#include <map>

#include "component.h"

namespace galaxy {

class GameObject
{
public:
  enum class Projection
  {
    Perspective,
    Orthographic
  };

  GameObject(const Projection projection = Projection::Perspective, const glm::vec3 &position = glm::vec3(0, 0, 0));
  ~GameObject();

  void update(std::chrono::nanoseconds &dt);
  void render(std::chrono::nanoseconds &dt);

  const Projection projection() const;
  const glm::vec3 &position() const;

  std::shared_ptr<GameObject> parent() const;
  std::vector<std::shared_ptr<GameObject>> children() const;

  // std::vector<std::shared_ptr<Component>> components() const;
  // void addComponent

private:
  std::shared_ptr<GameObject> parent_;
  std::vector<std::shared_ptr<GameObject>> children_;

  Projection projection_;
  glm::vec3 position_;

  std::vector<std::shared_ptr<Component>> components_;
};

} // namespace galaxy

#endif // GALAXY_GAMEOBJECT_H