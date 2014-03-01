#ifndef GALAXY_FONT_MANAGER_H
#define GALAXY_FONT_MANAGER_H

#include <map>
#include <memory>
#include <string>

typedef struct FT_FaceRec_ *FT_Face;
typedef struct FT_LibraryRec_ *FT_Library;

struct FT_FaceRec_;
struct FT_LibraryRec_;
namespace boost { namespace filesystem { class path; }}

namespace gxy {

typedef std::map<std::string, std::shared_ptr<FT_Face>> FontMap;
class FontManager final : private FontMap
{
public:
  FontManager();
  FontManager(const FontManager &) = delete;
  FontManager &operator =(FontManager) = delete;

  using FontMap::at;
  using FontMap::empty;

  void push(const std::string &name, const boost::filesystem::path &file);

private:
  std::unique_ptr<FT_Library> freetype_;
};

} // namespace gxy

#endif // GALAXY_FONT_MANAGER_H
