#include "fontmanager.h"

#include <cassert>

#include <boost/filesystem.hpp>

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

void FontManager::push(const std::string &name, const boost::filesystem::path &file)
{
  auto face = std::make_shared<FT_Face>();
  auto fullpath = myGame()->assets() / file;
  LOG(INFO) << fullpath;

  auto ret = FT_New_Face(*freetype_.get(), fullpath.c_str(), 0, face.get());
  assert(ret == 0);

  insert({name, face});
}

} // namespace gxy
