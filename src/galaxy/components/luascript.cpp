#include "luascript.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <cassert>
#include <cstdint>
#include <glog/logging.h>
#include <luabind/luabind.hpp>
#include <string>

#include "../components.h"
#include "../game.h"

namespace galaxy {
namespace components {

LuaScript::LuaScript(const char *const file, const LuaLib libraries, const char *const method) : Component(ComponentType::LuaScript),
  L(luaL_newstate()), libraries_(libraries), script_(myGame()->assets()), method_(method), has_method_(false)
{
  assert(L);
  script_.append(file);
  LOG(INFO) << "New Lua Script: " << script_;

  {
    // These two arrays must stay in the same order.
    const LuaLib libraries[] = { BasicLib, IOLib, OSLib, StringLib, TableLib, MathLib, DebugLib, PackageLib };
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

    const int n = sizeof(libraries) / sizeof(libraries[0]);
    for (uint32_t i = 0; i < n; ++i) {
      if (libraries[i] & libraries_) {
        LOG(INFO) << "Loading Lua library: " << (strcmp(lualibs[i].name, "") == 0 ? "base" : lualibs[i].name);
        lua_pushcfunction(L, lualibs[i].func);
        lua_pushstring(L, lualibs[i].name);
        lua_call(L, 1, 0);
      }
    }
  }

  int ret = luaL_dofile(L, script_.c_str());
  assert(ret == 0);

  luabind::open(L);

  luabind::object func = luabind::globals(L)[method_];
  has_method_ = func && luabind::type(func) == LUA_TFUNCTION;
}

LuaScript::~LuaScript()
{
}

void LuaScript::update(const std::chrono::nanoseconds &dt)
{
  if (has_method_) {
    luabind::call_function<void>(L, method_, static_cast<long>(dt.count()));
  }
}

void LuaScript::render(const std::chrono::nanoseconds &dt)
{
}


} // namespace component
} // namespace galaxy
