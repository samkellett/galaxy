#include "text2d.h"

namespace galaxy {
namespace object {

Text2D::Data::Data(const double x, const double y) :
  x(x), y(y)
{
}

Text2D::Text2D(const Text2D::Data &data) :
  x_(data.x), y_(data.y)
{
  LOG(INFO) << "Text2D -- x: " << x_ << ", y: " << y_;
}

} // namespace object
} // namespace galaxy