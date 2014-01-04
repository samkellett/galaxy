#include "luascript.h"

#include <cassert>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "../components.h"

namespace galaxy {
namespace components {

LuaScript::LuaScript() : Component(ComponentType::LuaScript),
  state_(luaL_newstate())
{
  assert(state_);
}

LuaScript::~LuaScript()
{
}

void LuaScript::update(const std::chrono::nanoseconds &dt)
{
}

void LuaScript::render(const std::chrono::nanoseconds &dt)
{
}


} // namespace component
} // namespace galaxy
