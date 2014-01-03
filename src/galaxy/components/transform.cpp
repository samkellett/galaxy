#include "transform.h"

namespace galaxy {
namespace component {

Transform::Transform() : 
  position_(0, 0, 0), rotation_(0, 0, 0), scale_(1, 1, 1)
{
}

Transform::~Transform()
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
} // namespace galaxy
