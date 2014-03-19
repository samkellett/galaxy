#include "face.h"

#include <cassert>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "logger.h"

namespace gxy {

Face::Face(std::unique_ptr<FT_Face> &ftface, const unsigned int size)
{
  auto face = std::move(ftface);
  FT_Set_Pixel_Sizes(*face.get(), 0, size);


  for (char c = 32; c <= 126; ++c) {
    if(FT_Load_Char(*face.get(), c, FT_LOAD_RENDER)) {
      LOG(ERROR) << "Could not load character: " << c;
      continue;
    }

    glyphs_[c - 32] = (*face)->glyph;
  }
}

FT_GlyphSlot &Face::glyph(const char character)
{
  auto code = static_cast<unsigned int>(character) - 32;
  assert(character >= 32 && code < glyphs_.size());

  return glyphs_.at(code);
}

} // namespace gxy
