#ifndef GALAXY_FONT_MANAGER_H
#define GALAXY_FONT_MANAGER_H

#include <map>
#include <memory>
#include <string>

#include "face.h"
#include "mixins/gameable.h"

struct FT_LibraryRec_;
typedef struct FT_LibraryRec_ *FT_Library;

namespace YAML { class Node; }

namespace gxy {

class Game;

typedef std::map<std::string, Face> FontMap;

class FontManager final : private FontMap, public mixins::Gameable
{
public:
  FontManager() = delete;
  FontManager(Game &game);
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
