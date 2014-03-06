#include "luastate.h"

#include <cassert>
#include <cstdint>

extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

#include <luabind/luabind.hpp>

#include "game.h"
#include "logger.h"

namespace gxy {

LuaState::LuaState() :
  L(luaL_newstate())
{
  assert(L);
}

LuaState::operator lua_State *() const
{
  return L;
}

void LuaState::init(const std::shared_ptr<Game> g)
{
  setGame(g);
  if (file_.is_relative()) {
    file_ = game()->assets() / file_;
  }
  assert(boost::filesystem::exists(file_));

  LOG(INFO) << "New Lua Script: " << file_;

  // TODO: Make these std::array's
  // These two arrays must stay in the same order.
  const Libraries libraries[] = { Libraries::BasicLib, Libraries::IOLib, Libraries::OSLib, Libraries::StringLib, Libraries::TableLib, Libraries::MathLib, Libraries::DebugLib, Libraries::PackageLib };
  const luaL_Reg lualibs[] = {
    { "", luaopen_base },
    { LUA_IOLIBNAME, luaopen_io },
    { LUA_OSLIBNAME, luaopen_os },
    { LUA_STRLIBNAME, luaopen_string },
    { LUA_TABLIBNAME, luaopen_table },
    { LUA_MATHLIBNAME, luaopen_math },
    { LUA_DBLIBNAME, luaopen_debug },
    { LUA_LOADLIBNAME, luaopen_package }
  };

  const auto n = sizeof(libraries) / sizeof(libraries[0]);
  for (uint32_t i = 0; i < n; ++i) {
    if (libraries[i] & libraries_) {
      LOG(INFO) << "Loading Lua library: " << (strcmp(lualibs[i].name, "") == 0 ? "base" : lualibs[i].name);
      lua_pushcfunction(L, lualibs[i].func);
      lua_pushstring(L, lualibs[i].name);
      lua_call(L, 1, 0);
    }
  }

  int ret = luaL_dofile(L, file_.c_str());
  if (ret != 0) {
    LOG(ERROR) << lua_tostring(L, -1);
  }
  assert(ret == 0);

  luabind::open(L);
}

void LuaState::setFile(const boost::filesystem::path &file)
{
  file_ = file;
}

const boost::filesystem::path &LuaState::file() const
{
  return file_;
}

void LuaState::setLibraries(const LuaState::Libraries &libraries)
{
  libraries_ = libraries;
}

const LuaState::Libraries &LuaState::libraries() const
{
  return libraries_;
}

bool operator &(const LuaState::Libraries &lhs, const LuaState::Libraries &rhs)
{
  return static_cast<int>(lhs) & static_cast<int>(rhs);
}

} // namespace gxy

namespace YAML {

typedef gxy::LuaState::Libraries Libraries;

Node convert<Libraries>::encode(const Libraries &libs)
{
  return Node(static_cast<int>(libs));
}

bool convert<Libraries>::decode(const Node &node, Libraries &libs)
{
  auto value = node.as<std::string>();

  if (value == "NoLibs") {
    libs = Libraries::NoLibs;
  } else if (value == "BasicLib") {
    libs = Libraries::BasicLib;
  } else if (value == "IOLib") {
    libs = Libraries::IOLib;
  } else if (value == "OSLib") {
    libs = Libraries::OSLib;
  } else if (value == "StringLib") {
    libs = Libraries::StringLib;
  } else if (value == "TableLib") {
    libs = Libraries::TableLib;
  } else if (value == "MathLib") {
    libs = Libraries::MathLib;
  } else if (value == "DebugLib") {
    libs = Libraries::DebugLib;
  } else if (value == "PackageLib") {
    libs = Libraries::PackageLib;
  } else if (value == "CoreLibs") {
    libs = Libraries::CoreLibs;
  } else {
    libs = static_cast<Libraries>(node.as<int>());
  }

  return true;
}

} // namespace YAML
