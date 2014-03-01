#include "gameobject.h"

#include <algorithm>
#include <cassert>

#include "componentmanager.h"

namespace gxy {

GameObject::GameObject(const std::string &name, std::shared_ptr<GameObject> parent) :
  name_(name), parent_(parent)
{
  if (parent) {
    parent->addChild(shared_from_this());
  }
}

const std::string &GameObject::name() const
{
  return name_;
}

ComponentManager &GameObject::components()
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

} // namespace gxy
