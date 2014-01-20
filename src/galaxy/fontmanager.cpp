#include "fontmanager.h"

#include <cassert>

#include "game.h"
#include "logger.h"

namespace galaxy {

FontManager::FontManager()
{
  auto ret = FT_Init_FreeType(&freetype_);
  assert(ret == 0);
}

FontManager::~FontManager()
{
}

void FontManager::push(const std::string &name, const std::string &file)
{
  size_t path = file.find_last_of("/\\");
  size_t ext = file.find_last_of(".");
  std::string font = file.substr(path + 1, ext - path - 1);

  auto face = std::make_shared<FT_Face>();
  std::string fullpath = std::string(myGame()->assets() + file);

  LOG(INFO) << fullpath;

  auto ret = FT_New_Face(freetype_, fullpath.c_str(), 0, face.get());
  assert(ret == 0);

  fonts_.insert({font.c_str(), face});
}

std::shared_ptr<FT_Face> FontManager::at(const std::string &key) const
{
  return fonts_.at(key);
}

} // namespace galaxy
