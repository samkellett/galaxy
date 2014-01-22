#ifndef GALAXY_FONT_MANAGER_H
#define GALAXY_FONT_MANAGER_H

#include <map>
#include <memory>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace gxy {

class FontManager
{
public:
  FontManager();
  ~FontManager();

  void push(const std::string &name, const std::string &file);
  std::shared_ptr<FT_Face> at(const std::string &key) const;

private:
  FT_Library freetype_;
  std::map<std::string, std::shared_ptr<FT_Face>> fonts_;
};

} // namespace gxy

#endif // GALAXY_FONT_MANAGER_H
