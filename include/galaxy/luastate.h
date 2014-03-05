#ifndef GALAXY_LUASTATE_H
#define GALAXY_LUASTATE_H

#include <string>

#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

#include "mixins/gameable.h"

class lua_State;

namespace gxy {

class LuaState : public mixins::Gameable
{
public:
  enum class Libraries
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

  LuaState();
  operator lua_State *() const;

  void init();

  void setFile(const boost::filesystem::path &file);
  const boost::filesystem::path &file() const;

  void setLibraries(const Libraries &libraries);
  const Libraries &libraries() const;

private:
  lua_State *L;
  Libraries libraries_;
  boost::filesystem::path file_;
};

bool operator &(const LuaState::Libraries &lhs, const LuaState::Libraries &rhs);

} // namespace gxy

namespace YAML {

template <>
struct convert<gxy::LuaState::Libraries>
{
  static Node encode(const gxy::LuaState::Libraries &libs);
  static bool decode(const Node &node, gxy::LuaState::Libraries &libs);
};

} // namespace YAML

#endif // GALAXY_LUASTATE_H
