#ifndef GXY_GUI_LABEL_H
#define GXY_GUI_LABEL_H

#include <string>

#include "widget.h"

typedef struct FT_FaceRec_ *FT_Face;
struct FT_FaceRec_;

namespace gxy {

class LuaState;

namespace gui {

class Label : public Widget
{
public:
  Label(const unsigned int x, const unsigned int y, const std::shared_ptr<Game> game);
  void render(const std::chrono::nanoseconds &dt);

  void setText(const std::string &text);

private:
  unsigned int x_;
  unsigned int y_;

  std::shared_ptr<FT_Face> face_;
  std::string text_;
};

template <>
void load_bindings<Label>(const LuaState &state);

} // namespace gui
} // namespace gxy

#endif // GXY_GUI_LABEL_H
