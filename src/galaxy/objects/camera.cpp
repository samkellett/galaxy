#include "camera.h"

#include "components/transform.h"

namespace galaxy {
namespace objects {

Camera::Camera() : GameObject()
{
  components()->push<components::Transform>();
}

} // namespace object
} // namespace galaxy
