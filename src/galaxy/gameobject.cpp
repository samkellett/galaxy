#include "gameobject.h"

namespace galaxy {

GameObject::GameObject(const Projection projection, const glm::vec3 &position) :
  projection_(projection), position_(position)
{
}

GameObject::~GameObject()
{
}

const GameObject::Projection GameObject::projection() const
{
  return projection_;
}

const glm::vec3 &GameObject::position() const
{
  return position_;
}

std::shared_ptr<GameObject> GameObject::parent() const
{
  return parent_;
}

std::vector<std::shared_ptr<GameObject>> GameObject::children() const
{
  return children_;
}

} // namespace galaxy
