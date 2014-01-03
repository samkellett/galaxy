#include "gameobject.h"

#include <cassert>

namespace galaxy {

GameObject::GameObject(const std::shared_ptr<GameObject> &parent) :
  components_(new ComponentManager), parent_(parent)
{
  if (parent) {
    parent->addChild(shared_from_this());
  }
}

GameObject::~GameObject()
{
}

void GameObject::update(std::chrono::nanoseconds &dt)
{
  for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator) {
    (*iterator)->update(dt);
  }
}

void GameObject::render(std::chrono::nanoseconds &dt)
{
  for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator) {
    (*iterator)->render(dt);
  }
}

const std::shared_ptr<ComponentManager> GameObject::components() const
{
  return components_;
}

void GameObject::setParent(const std::shared_ptr<GameObject> &parent)
{
  parent_ = parent;

#ifdef GALAXY_DEBUG
  auto children = parent_->children();

  assert(std::find(children.begin(), children.end(), shared_from_this()) != children.end());
#endif
}

const std::shared_ptr<GameObject> GameObject::parent() const
{
  return parent_;
}

void GameObject::addChild(const std::shared_ptr<GameObject> &child)
{
  children_.push_back(child);
  if (child->parent().get() != this) {
    child->setParent(shared_from_this());
  }
}

const std::vector<std::shared_ptr<GameObject>> GameObject::children() const
{
  return children_;
}

} // namespace galaxy
