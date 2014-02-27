#include "fontmanager.h"

#include <cassert>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "game.h"
#include "logger.h"

namespace gxy {

FontManager::FontManager() :
  freetype_(new FT_Library)
{
  auto ret = FT_Init_FreeType(freetype_.get());
  assert(ret == 0);
}

void FontManager::push(const std::string &name, const std::string &file)
{
  std::size_t path = file.find_last_of("/\\");
  std::size_t ext = file.find_last_of(".");
  std::string font = file.substr(path + 1, ext - path - 1);

  auto face = std::make_shared<FT_Face>();
  std::string fullpath = std::string(myGame()->assets() + file);

  LOG(INFO) << fullpath;

  auto ret = FT_New_Face(*freetype_.get(), fullpath.c_str(), 0, face.get());
  assert(ret == 0);

  insert({font.c_str(), face});
}

} // namespace gxy
