#ifndef GALAXY_COMPONENTS_TRANSFORM_H
#define GALAXY_COMPONENTS_TRANSFORM_H

#include "../component.h"

#include <glm/glm.hpp>

namespace galaxy {
namespace component {

class Transform : public Component
{
public:
  Transform();
  ~Transform();

private:
  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_;
};

} // namespace component
} // namespace galaxy

#endif // GALAXY_COMPONENTS_TRANSFORM_H
