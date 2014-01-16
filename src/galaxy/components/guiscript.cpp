#include "guiscript.h"

namespace galaxy {
namespace components {

GuiScript::GuiScript(const char *const file, const LuaLib libraries) : LuaScript(file, libraries, "onGui")
{
}

} // namespace components
} // namespace galaxy
