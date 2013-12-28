#ifndef GALAXY_GAMEOBJECT_H
#define GALAXY_GAMEOBJECT_H

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

  const Projection projection() const;
  const glm::vec3 &position() const;

  std::shared_ptr<GameObject> parent() const;
  std::vector<std::shared_ptr<GameObject>> children() const;

private:
  std::shared_ptr<GameObject> parent_;
  std::vector<std::shared_ptr<GameObject>> children_;

  Projection projection_;
  glm::vec3 position_;
};

} // namespace galaxy

#endif // GALAXY_GAMEOBJECT_H