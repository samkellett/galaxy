#include "text2d.h"

namespace galaxy {
namespace object {

Text2D::Data::Data(const double x, const double y) :
  x(x), y(y)
{
}

Text2D::Text2D(const Text2D::Data &data) :
  GameObject() //Orthographic, glm::vec3(data.x, data.y, 0))
{
  LOG(INFO) << "Text2D -- x: " << data.x << ", y: " << data.y;
}

} // namespace object
} // namespace galaxy
