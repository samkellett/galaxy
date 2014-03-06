#ifndef GXY_GUI_LABEL_H
#define GXY_GUI_LABEL_H

#include <string>

#include "widget.h"

namespace gxy {

class LuaState;

namespace gui {

class Label final : public Widget
{
public:
  static void init(const LuaState &state);
  void render(const std::chrono::nanoseconds &dt);

  void setText(const std::string &text);

private:
  std::string text_;
};

} // namespace gui
} // namespace gxy

#endif // GXY_GUI_LABEL_H
