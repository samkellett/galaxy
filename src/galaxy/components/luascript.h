#ifndef GALAXY_COMPONENT_LUASCRIPT_H
#define GALAXY_COMPONENT_LUASCRIPT_H

#include <string>

#include "../component.h"

class lua_State;

namespace gxy {
namespace components {

class LuaScript : public Component
{
public:
  enum LuaLib
  {
    NoLibs = 0x0,
    BasicLib = 0x1,
    IOLib = 0x2,
    OSLib = 0x4,
    StringLib = 0x8,
    TableLib = 0x10,
    MathLib = 0x20,
    DebugLib = 0x40,
    PackageLib = 0x80,

    CoreLibs = BasicLib | IOLib | OSLib | StringLib | TableLib | MathLib | DebugLib | PackageLib
  };

  LuaScript(const char *const file, const LuaLib libraries = NoLibs);

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

protected:
  lua_State *L;
  const LuaLib libraries_;
  std::string script_;
};

} // namespace component
} // namespace gxy

#endif // GALAXY_COMPONENT_LUASCRIPT_H
