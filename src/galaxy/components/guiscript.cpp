#include "guiscript.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <luabind/luabind.hpp>

#include <boost/ref.hpp>

namespace galaxy {
namespace components {

GuiScript::GuiScript(const char *const file, const LuaLib libraries) : LuaScript(file, libraries),
  gui_(L)
{
}

void GuiScript::update(const std::chrono::nanoseconds &dt)
{
  luabind::call_function<void>(L, "onGui", static_cast<long>(dt.count()), boost::ref(gui_));
}

void GuiScript::render(const std::chrono::nanoseconds &)
{
  gui_.render();
}

} // namespace components
} // namespace galaxy
