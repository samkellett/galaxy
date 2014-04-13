#include "face.h"

#include <cassert>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "gfx.h"
#include "logger.h"

namespace gxy {

Face::Face(std::unique_ptr<FT_Face> &ftface, const unsigned int size)
{
  auto face = std::move(ftface);
  auto *glyph = (*face)->glyph;

  FT_Set_Pixel_Sizes(*face.get(), 0, size);

  for (char c = 32; c <= 126; ++c) {
    if(FT_Load_Char(*face.get(), c, FT_LOAD_RENDER)) {
      LOG(ERROR) << "Could not load character: " << c;
      continue;
    }

    auto texture = Texture(glyph->bitmap.buffer, glyph->bitmap.width, glyph->bitmap.rows, 8, GL_R8, false);
    texture.setFiltering(Texture::Minification::Bilinear, Texture::Magnification::Bilinear);
    texture.setSamplerParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    texture.setSamplerParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glyphs_[c - 32] = FT_GlyphSlot(glyph);
    textures_[c - 32] = texture;
  }
}

const FT_GlyphSlot &Face::glyph(const char character) const
{
  auto code = static_cast<unsigned int>(character) - 32;
  assert(character >= 32 && code < glyphs_.size());

  return glyphs_.at(code);
}

const Texture &Face::texture(const char character) const
{
  auto code = static_cast<unsigned int>(character) - 32;
  assert(character >= 32 && code < textures_.size());

  return textures_.at(code);
}

} // namespace gxy
