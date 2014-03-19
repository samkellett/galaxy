#include "gameobject.h"

#include <algorithm>
#include <cassert>

#include "componentmanager.h"
#include "game.h"

namespace gxy {

GameObject::GameObject(Game &g, const std::string &name, const boost::optional<GameObject &> &parent) : mixins::Gameable(g),
  name_(name),
  parent_(parent),
  components_(game())
{
  if (parent) {
    (*parent).addChild(*this);
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

void GameObject::setParent(GameObject &parent)
{
  parent_ = parent;
}

const boost::optional<GameObject &> &GameObject::parent() const
{
  return parent_;
}

void GameObject::addChild(GameObject &child)
{
  children_.push_back(std::ref(child));
  child.setParent(*this);
}

const std::vector<std::reference_wrapper<GameObject>> &GameObject::children() const
{
  return children_;
}

} // namespace gxy
