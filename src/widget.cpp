#include "gui/widget.h"

namespace gxy {
namespace gui {

Widget::Widget(std::shared_ptr<Game> game) : mixins::Gameable(game)
{
}

} // namespace gui
} // namespace gxy
