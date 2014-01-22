#include "component.h"

namespace gxy {

Component::Component(const ComponentType type) :
  type_(type)
{
}

Component::~Component()
{
}

const ComponentType Component::type() const
{
  return type_;
}

} // namespace gxy
