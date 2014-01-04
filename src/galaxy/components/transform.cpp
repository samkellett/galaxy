#include "transform.h"

#include "../components.h"

namespace galaxy {
namespace components {

Transform::Data::Data(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
  position_(position), rotation_(rotation), scale_(scale)
{ 
}

Transform::Transform() : Component(ComponentType::Transform),
  position_(0, 0, 0), rotation_(0, 0, 0), scale_(1, 1, 1)
{
}

Transform::Transform(const Transform::Data &data) : Component(ComponentType::Transform),
  position_(data.position_), rotation_(data.rotation_), scale_(data.scale_)
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
