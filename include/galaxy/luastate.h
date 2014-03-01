#ifndef GALAXY_LUASTATE_H
#define GALAXY_LUASTATE_H

#include <string>

#include <boost/filesystem.hpp>

class lua_State;

namespace gxy {

class LuaState
{
public:
  enum Libraries
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

  LuaState(const boost::filesystem::path &file, const Libraries libraries);
  operator lua_State *() const;

private:
  lua_State *L;
  const Libraries libraries_;
  boost::filesystem::path file_;
};

} // namespace gxy

#endif // GALAXY_LUASTATE_H
