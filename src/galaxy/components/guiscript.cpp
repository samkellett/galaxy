#include "guiscript.h"

#include <boost/ref.hpp>
#include <luabind/luabind.hpp>

#include "../components.h"
#include "../game.h"

namespace gxy {
namespace components {

GuiScript::GuiScript(const char *const file) : GuiScript(file, LuaState::Libraries::NoLibs)
{
}

GuiScript::GuiScript(const char *const file, const LuaState::Libraries libraries) : Component(ComponentType::GuiScript),
  state_(std::string(myGame()->assets()) + file, libraries)
{
  using luabind::module;
  using luabind::class_;

  module(state_)
  [
    class_<GuiScript>("GuiScript")
      .def("drawLabel", &GuiScript::drawLabel)
  ];
}

void GuiScript::update(const std::chrono::nanoseconds &dt)
{
  luabind::call_function<void>(state_, "onGui", static_cast<long>(dt.count()), boost::ref(*this));
}

void GuiScript::render(const std::chrono::nanoseconds &)
{
}

// Drawing API:
void GuiScript::drawLabel(const uint32_t x, const uint32_t y, const char *const text)
{
}

} // namespace components
} // namespace gxy
