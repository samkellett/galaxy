#include "transform.h"

#include "components.h"

namespace gxy {
namespace components {

Transform::Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) : Component(ComponentType::Transform),
  position_(position), rotation_(rotation), scale_(scale)
{
}

void Transform::update(const std::chrono::nanoseconds &)
{
}

void Transform::render(const std::chrono::nanoseconds &)
{
}

const glm::vec3 &Transform::position() const
{
  return position_;
}

const glm::vec3 &Transform::rotation() const
{
  return rotation_;
}

const glm::vec3 &Transform::scale() const
{
  return scale_;
}

} // namespace component
} // namespace gxy
