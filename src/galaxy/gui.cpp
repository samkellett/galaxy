#include "gui.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <luabind/luabind.hpp>

#include "logger.h"

namespace galaxy {

Gui::Gui(lua_State *L)
{
  using luabind::module;
  using luabind::class_;

  module(L)
  [
    class_<Gui>("Gui")
      .def("drawLabel", &Gui::drawLabel)
  ];
}

void Gui::render()
{
}

// Drawing API
void Gui::drawLabel(const uint32_t x, const uint32_t y, const char *const text)
{
  LOG(INFO) << "LABEL: " << text;
}

} // namespace galaxy
