#ifndef GXY_TEXTURE_H
#define GXY_TEXTURE_H

#include <cstdint>

namespace boost { namespace filesystem { class path; }}

namespace gxy {

class Texture
{
public:
  enum class Minification
  {
    Nearest,
    Bilinear,
    NearestMipmap,
    BilinearMipmap,
    Trilinear
  };

  enum class Magnification
  {
    Nearest,
    Bilinear
  };

  Texture(const uint8_t *const data, const unsigned int width, const unsigned int height, const unsigned int bpp, const int format, const bool mipmaps);
  Texture(const boost::filesystem::path &file, const bool mipmaps);

  void load(const uint8_t *const data, const unsigned int width, const unsigned int height, const unsigned int bpp, const int format, const bool mipmaps);
  void load(const boost::filesystem::path &file, const bool mipmaps);

  void clear();

  void setFiltering(const Minification &min, const Magnification &mag);
  void setSamplerParameter(const int key, const int value);

  Minification minification() const;
  Magnification magnification() const;

  unsigned int width() const;
  unsigned int height() const;
  int bpp() const;

private:
  unsigned int id_;
  unsigned int sampler_;
  bool mipmaps_;

  unsigned int width_;
  unsigned int height_;
  unsigned int bpp_;

  Magnification mag_;
  Minification min_;
};

} // namespace gxy

#endif // GXY_TEXTURE_H
