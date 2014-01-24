#ifndef GALAXY_FONT_MANAGER_H
#define GALAXY_FONT_MANAGER_H

#include <map>
#include <memory>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace gxy {

typedef std::map<std::string, std::shared_ptr<FT_Face>> FontMap;
class FontManager : private FontMap
{
public:
  FontManager();
  FontManager(const FontManager &) = delete;
  FontManager &operator =(FontManager) = delete;

  using FontMap::at;
  void push(const std::string &name, const std::string &file);

private:
  FT_Library freetype_;
};

} // namespace gxy

#endif // GALAXY_FONT_MANAGER_H
