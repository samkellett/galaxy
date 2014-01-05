#include "luascript.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <cassert>
#include <glog/logging.h>
#include <luabind/luabind.hpp>
#include <string>

#include "../components.h"

namespace galaxy {
namespace components {

LuaScript::Data::Data(const char *script) :
  script_(script)
{
}

LuaScript::LuaScript(const char *const file) : Component(ComponentType::LuaScript),
  state_(luaL_newstate()), script_(file), has_update_(false)
{
  assert(state_);

  luaL_openlibs(state_);

  int ret = luaL_dofile(state_, script_);
  assert(ret == 0);

  luabind::set_pcall_callback([](lua_State *L) {
    // log the error message
    luabind::object msg(luabind::from_stack(L, -1));
    std::ostringstream str;
    str << "Lua run-time error: " << msg;

    // log the callstack
    std::string traceback = luabind::call_function<std::string>(luabind::globals(L)["debug"]["traceback"]);
    LOG(INFO) << str.str() << "\nLua " << traceback;

    // return unmodified error object
    return 1;
  });

  luabind::open(state_);

  luabind::object update = luabind::globals(state_)["onUpdate"];
  has_update_ = update && luabind::type(update) == LUA_TFUNCTION;
}

LuaScript::LuaScript(const LuaScript::Data &data) : LuaScript(data.script_)
{
}

LuaScript::~LuaScript()
{
}

void LuaScript::update(const std::chrono::nanoseconds &dt)
{
  if (has_update_) {
    luabind::call_function<void>(state_, "onUpdate", static_cast<long>(dt.count()));
  }
}

void LuaScript::render(const std::chrono::nanoseconds &dt)
{
}


} // namespace component
} // namespace galaxy
