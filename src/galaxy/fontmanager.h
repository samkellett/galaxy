#ifndef GALAXY_FONT_MANAGER_H
#define GALAXY_FONT_MANAGER_H

#include <map>
#include <memory>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace galaxy {

class FontManager
{
public:
  FontManager();
  ~FontManager();

  void push(const char *const name, const std::string &file);

private:
  FT_Library freetype_;
  std::map<const char *const, std::shared_ptr<FT_Face>> fonts_;
};

} // namespace galaxy

#endif // GALAXY_FONT_MANAGER_H
