#include "luascript.h"

#include <luabind/luabind.hpp>

#include "components.h"
#include "game.h"

namespace gxy {
namespace components {

LuaScript::LuaScript(const std::string &file) : LuaScript(file, LuaState::Libraries::NoLibs)
{
}

LuaScript::LuaScript(const std::string &file, const LuaState::Libraries libraries) : Component(ComponentType::LuaScript),
  state_(myGame()->assets() / file, libraries)
{
}

void LuaScript::update(const std::chrono::nanoseconds &dt)
{
  luabind::call_function<void>(state_, "onUpdate", static_cast<long>(dt.count()));
}

void LuaScript::render(const std::chrono::nanoseconds &)
{
}


} // namespace component
} // namespace gxy
