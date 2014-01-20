#include "guiscript.h"

#include <utility>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <luabind/luabind.hpp>

namespace glxy {
namespace components {

GuiScript::GuiScript(const char *const file, const LuaLib libraries) : LuaScript(file, libraries)
{
  using luabind::module;
  using luabind::class_;

  module(L)
  [
    class_<GuiScript>("GuiScript")
      .def("drawLabel", &GuiScript::drawLabel)
  ];
}

void GuiScript::update(const std::chrono::nanoseconds &dt)
{
  luabind::call_function<void>(L, "onGui", static_cast<long>(dt.count()), std::ref(*this));
}

void GuiScript::render(const std::chrono::nanoseconds &)
{
}

// Drawing API:
void GuiScript::drawLabel(const uint32_t x, const uint32_t y, const char *const text)
{
}

} // namespace components
} // namespace glxy
