#include "fontmanager.h"

#include <cassert>

#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "game.h"
#include "logger.h"

namespace gxy {

FontManager::FontManager(Game &game) : mixins::Gameable(game),
  freetype_(new FT_Library)
{
  auto ret = FT_Init_FreeType(freetype_.get());
  assert(ret == 0);
}

void FontManager::push(const YAML::Node &data)
{
  auto name = data["name"].as<std::string>();
  boost::filesystem::path path(data["path"].as<std::string>());
  LOG(INFO) << "Adding font: " << name << ", at: " << path;

  auto face = std::make_shared<FT_Face>();
  auto fullpath = game().assets() / path;
  assert(boost::filesystem::exists(fullpath));

  auto ret = FT_New_Face(*freetype_.get(), fullpath.c_str(), 0, face.get());
  assert(ret == 0);

  insert({name, face});
}

} // namespace gxy
