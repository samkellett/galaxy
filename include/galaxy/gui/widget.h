#ifndef GALAXY_WIDGET_H
#define GALAXY_WIDGET_H

#include <chrono>

namespace gxy {
namespace gui {

class Widget
{
public:
  virtual void render(const std::chrono::nanoseconds &dt) = 0;
};

} // namespace gui
} // namespace gxy

#endif // GALAXY_WIDGET_H
