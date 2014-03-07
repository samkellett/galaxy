#include "gui/widget.h"

#include "gui/pen.h"

namespace gxy {
namespace gui {

Widget::Widget(std::shared_ptr<GuiScript> gui) : mixins::Gameable(gui->game()),
  pen_(gui->pen())
{
}

} // namespace gui
} // namespace gxy
