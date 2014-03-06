#include "label.h"

#include <luabind/luabind.hpp>

#include "logger.h"
#include "luastate.h"

namespace gxy {
namespace gui {

void Label::init(const LuaState &state)
{
  using luabind::module;
  using luabind::class_;

  module(state)
  [
    class_<Label>("Label")
      .def("setText", &Label::setText)
  ];
}

void Label::setText(const std::string &text)
{
  LOG(INFO) << text;
}

void Label::render()
{
}

} // namespace gui
} // namespace gxy
