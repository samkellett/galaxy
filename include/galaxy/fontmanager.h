#ifndef GALAXY_FONT_MANAGER_H
#define GALAXY_FONT_MANAGER_H

#include <map>
#include <memory>
#include <string>

#include "mixins/gameable.h"

typedef struct FT_FaceRec_ *FT_Face;
typedef struct FT_LibraryRec_ *FT_Library;

struct FT_FaceRec_;
struct FT_LibraryRec_;

namespace YAML { class Node; }

namespace gxy {

class Game;

typedef std::map<std::string, std::shared_ptr<FT_Face>> FontMap;
class FontManager final : private FontMap, public mixins::Gameable
{
public:
  FontManager() = delete;
  FontManager(const std::shared_ptr<Game> game);
  FontManager(const FontManager &) = delete;
  FontManager &operator =(FontManager) = delete;

  using FontMap::at;
  using FontMap::count;
  using FontMap::empty;

  void push(const YAML::Node &data);

private:
  std::unique_ptr<FT_Library> freetype_;
};

} // namespace gxy

#endif // GALAXY_FONT_MANAGER_H
