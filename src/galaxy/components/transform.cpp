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

} // namespace component
} // namespace galaxy
