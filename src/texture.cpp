#include "texture.h"

#include <fstream>
#include <memory>

#include <boost/filesystem.hpp>
#include <png.h>

#include "gfx.h"

namespace {

struct Image
{
  Image(const std::ifstream &file) :
    read(nullptr),
    info(nullptr)
  {
    read = png_create_read_struct(PNG_LIBPNG_VER_STRING);
    if (!read) {
      throw unknown_texture(file);
    }

    info = png_create_info_struct(read);
    if (!info) {
      throw unknown_texture(file);
    }
  }

  ~Image()
  {
    png_destroy_read_struct(&read, &info, nullptr);
  }

  png_structp read;
  png_infop info;
};

bool validate_png(const std::ifstream &stream)
{
  png_byte header[8];

  stream.read(static_cast<uint8_t *>(header), 8);
  if (!stream.good()) {
    return false;
  }

  return png_sig_cmp(header, 0, 8) == 0;
}

void read_data(const png_structp png, const png_bytep data, const png_size_t length)
{
  png_voidp io = png_get_io_ptr(png);
  auto stream = static_cast<std::istream *>(io);
  stream->read(static_cast<uint8_t *>(data), length);
}

} // unnamed namespace

namespace gxy {

Texture::Texture() :
  mag_(Magnification::Nearest),
  min_(Minification::Nearest)
{
}

Texture::Texture(const uint8_t *const data, const unsigned int width, const unsigned int height, const unsigned int bpp, const int format, const bool mipmaps) : Texture()
{
  load(data, width, height, bpp, format, mipmaps);
}

Texture::Texture(const boost::filesystem::path &file, const bool mipmaps) : Texture()
{
  load(file, mipmaps);
}

Texture::~Texture()
{
  clear();
}

void Texture::load(const uint8_t *const data, const unsigned int width, const unsigned int height, const int bpp, const int format, const bool mipmaps)
{
  mipmaps_ = mipmaps;
  width_ = width;
  height_ = height;
  bpp_ = bpp;

  gfx::genTextures(1, &id_);
  gfx::bindTexture(GL_TEXTURE_2D, id_);

  if (format == GL_RGBA || format == GL_BGRA || format == GL_RGB || format == GL_BGR) {
    gfx::texImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, format, GL_UNSIGNED_BYTE, data);
  } else {
    gfx::texImage2D(GL_TEXTURE_2D, 0, format, width_, height_, 0, format, GL_UNSIGNED_BYTE, data);
  }

  if (mipmaps_) {
    gfx::generateMipmap(GL_TEXTURE_2D);
  }

  gfx::genSamplers(1, &sampler_);
}

void Texture::Texture::load(const boost::filesystem::path &path, const bool mipmaps)
{
  std::ifstream file(path.c_str());
  if (!validate_png(file)) {
    thrown unknown_texture(path);
  }

  Image png(file);
  if (setjmp(png_jmpbuf(png.read))) {
    throw unknown_texture(file);
  }

  png_set_read_fn(png.read, static_cast<png_voidp>(&file), read_data);
  png_set_sig_bytes(png.read, 8);
  png_read_info(png.read, png.info);

  png_uint_32 width = png_get_image_width(png.read, png.info);
  png_uint_32 height = png_get_image_height(png.read, png.info);
  png_uint_32 bitdepth = png_get_bit_depth(png.read, png.info);
  png_uint_32 channels = png_get_channels(png.read, png.info);
  png_uint_32 color_type = png_get_color_type(png.read, png.info);

  switch (color_type) {
    case PNG_COLOR_TYPE_PALETTE:
      png_set_palette_to_rgb(png.read);
      channels = 3;
      break;

    case PNG_COLOR_TYPE_GRAY:
      if (bitdepth < 8) {
        png_set_expand_gray_1_2_4_to_8(png.read);
      }
      bitdepth = 8;
      break;
  }

  if (png_get_valid(png.read, png.info, PNG_INFO_tRNS)) {
    png_set_tRNS_to_alpha(png.read);
    channels += 1;
  }

  if (bitdepth == 16) {
    png_set_strip_16(png.read);
  }

  auto rows = std::unique_ptr<png_bytep>(new png_bytep[height]);
  auto data = std::unique_ptr<uint8_t>(new uint8_t[width * height * bitdepth * channels / 8]);
  const unsigned int stride = width * bitdepth * channels / 8;

  for (size_t i = 0; i < height; i++) {
    png_uint_32 q = (height - i - 1) * stride;
    rows[i] = static_cast<png_bytep>(data.get()) + q;
  }

  png_read_image(png.read, rows.get());
  png_destroy_read_struct(&png.read, &png.info, nullptr);

  int format = 0;
  unsigned int bpp = bitdepth * channels;
  if (bpp == 32) {
    format = GL_RGBA;
  } else if (bpp == 24) {
    format = GL_BGR;
  } else if (bpp == 8) {
    format = GL_LUMINANCE;
  }

  load(data.get(), width, height, bpp, format, mipmaps);
}

void Texture::clear()
{
  gfx::deleteSamplers(1, &sampler_);
  gfx::deleteTextures(1, &id_);
}

void Texture::setFiltering(const Minification &min, const Magnification &mag)
{
  mag_ = mag;
  min_ = min;

  switch(min) {
    case Minification::Nearest:
      setSamplerParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      break;

    case Minification::Bilinear:
      setSamplerParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      break;

    case Minification::NearestMipmap:
      setSamplerParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
      break;

    case Minification::BilinearMipmap:
      setSamplerParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
      break;

    case Minification::Trilinear:
      setSamplerParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
      break;
  }

  switch(mag) {
    case Magnification::Nearest:
      setSamplerParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      break;

    case Magnification::Bilinear:
      setSamplerParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      break;
  }
}

void Texture::setSamplerParameter(const int key, const int value)
{
  gfx::sampleParameteri(sampler_, key, value);
}

Minification Texture::minification() const
{
  return min_;
}

Magnification Texture::magnification() const
{
  return mag_;
}

unsigned int Texture::width() const
{
  return width_;
}

unsigned int Texture::height() const
{
  return height_;
}

int Texture::bpp() const
{
  return bpp_;
}

} // namespace gxy
