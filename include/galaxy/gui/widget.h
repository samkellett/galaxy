#ifndef GALAXY_WIDGET_H
#define GALAXY_WIDGET_H

#include <chrono>
#include <memory>

#include "../mixins/gameable.h"

namespace gxy {

class GuiScript;
class LuaState;

namespace gui {

class Pen;

class Widget : public mixins::Gameable
{
public:
  Widget() = default;
  Widget(std::shared_ptr<GuiScript> gui);

  virtual void render(const std::chrono::nanoseconds &dt) = 0;

protected:
  std::shared_ptr<Pen> &pen();

private:
  const std::shared_ptr<Pen> pen_;
};

template <typename T>
void load_bindings(const LuaState &state);

} // namespace gui
} // namespace gxy

#endif // GALAXY_WIDGET_H
