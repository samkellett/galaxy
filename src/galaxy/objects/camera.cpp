#include "camera.h"

#include "components/transform.h"

namespace galaxy {
namespace objects {

Camera::Camera() : GameObject()
{
  components()->push<component::Transform>();
}

} // namespace objects
} // namespace galaxy
