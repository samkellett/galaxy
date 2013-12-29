#include "gameobject.h"

namespace galaxy {

GameObject::GameObject(const Projection projection, const glm::vec3 &position) :
  projection_(projection), position_(position)
{
}

GameObject::~GameObject()
{
}

void GameObject::update(std::chrono::nanoseconds &dt)
{
  for (auto iterator = components_.begin(); iterator != components_.end(); ++iterator) {
    (*iterator)->update(dt);
  }
}

void GameObject::render(std::chrono::nanoseconds &dt)
{
  for (auto iterator = components_.begin(); iterator != components_.end(); ++iterator) {
    (*iterator)->render(dt);
  }
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
