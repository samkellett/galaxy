#include "label.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <luabind/luabind.hpp>

#include "game.h"
#include "gfx.h"
#include "logger.h"
#include "luastate.h"
#include "scene.h"

#include "gui/pen.h"

namespace gxy {
namespace gui {

Label::Label(const unsigned int x, const unsigned int y, const std::shared_ptr<GuiScript> gui) : Widget(gui),
  x_(x),
  y_(y)
{
  auto scene = game()->scenes().current();
  face_ = scene->fonts().at(pen()->face());

  FT_Set_Pixel_Sizes(*face_.get(), 0, pen()->size());
}

void Label::render(const std::chrono::nanoseconds &)
{
  unsigned int x = x_;
  unsigned int y = y_;

  const float sx = 2.0 / game()->width();
  const float sy = 2.0 / game()->height();

  const auto glyph = (*face_)->glyph;

  for (const char &p : text_) {
    if(FT_Load_Char(*face_.get(), p, FT_LOAD_RENDER)) {
      LOG(ERROR) << "Could not load character: " << p;
      continue;
    }

    glTexImage2D(
      GL_TEXTURE_2D,
      0,
      GL_ALPHA,
      glyph->bitmap.width,
      glyph->bitmap.rows,
      0,
      GL_ALPHA,
      GL_UNSIGNED_BYTE,
      glyph->bitmap.buffer
    );

    // float x2 = x + glyph->bitmap_left * sx;
    // float y2 = -y - glyph->bitmap_top * sy;
    // float w = glyph->bitmap.width * sx;
    // float h = glyph->bitmap.rows * sy;

    // GLfloat box[4][4] = {
    //   {x2, -y2, 0, 0},
    //   {x2 + w, -y2, 1, 0},
    //   {x2, -y2 - h, 0, 1},
    //   {x2 + w, -y2 - h, 1, 1},
    // };

    // glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_DYNAMIC_DRAW);
    // glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    x += (glyph->advance.x >> 6) * sx;
    y += (glyph->advance.y >> 6) * sy;
  }
}

void Label::setText(const std::string &text)
{
  LOG(INFO) << text;
  text_ = text;
}

template <>
void load_bindings<Label>(const LuaState &state)
{
  using luabind::module;
  using luabind::class_;

  module(state)
  [
    class_<Label>("Label")
      .def("setText", &Label::setText)
  ];
}

} // namespace gui
} // namespace gxy
