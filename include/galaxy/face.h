#ifndef GXY_FACE_H
#define GXY_FACE_H

#include <array>
#include <memory>

#include "texture.h"

struct FT_FaceRec_;
struct FT_GlyphSlotRec_;

typedef struct FT_FaceRec_ *FT_Face;
typedef struct FT_GlyphSlotRec_ *FT_GlyphSlot;

namespace gxy {

class Face
{
public:
  Face(std::unique_ptr<FT_Face> &ftface, unsigned int size);

  const FT_GlyphSlot &glyph(const char character) const;
  const Texture &texture(const char character) const;

private:
  std::array<FT_GlyphSlot, 95> glyphs_;
  std::array<Texture, 95> textures_;
};

} // namespace gxy

#endif // GXY_FACE_H
