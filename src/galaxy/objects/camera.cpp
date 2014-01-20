#include "camera.h"

#include "components/transform.h"

namespace glxy {
namespace objects {

Camera::Camera(const char *const name) : GameObject(name)
{
  using components::Transform;

  components().push<Transform>();
}

} // namespace object
} // namespace glxy
