#ifndef GALAXY_COMPONENT_LUASCRIPT_H
#define GALAXY_COMPONENT_LUASCRIPT_H

#include <stdio.h>
#include <string>

#include "../component.h"

class lua_State;

namespace galaxy {
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

  LuaScript(const char *const file, const LuaLib libraries = NoLibs, const char *const method = "onUpdate");
  ~LuaScript();

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

private:
  lua_State *L;
  const LuaLib libraries_;
  std::string script_;

  const char *const method_;
  bool has_method_;
};

} // namespace component
} // namespace galaxy

#endif // GALAXY_COMPONENT_LUASCRIPT_H
