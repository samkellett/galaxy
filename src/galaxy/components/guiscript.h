#ifndef GALAXY_COMPONENTS_GUISCRIPT_H
#define GALAXY_COMPONENTS_GUISCRIPT_H

#include "luascript.h"

namespace galaxy {
namespace components {

class GuiScript : public LuaScript
{
public:
  GuiScript(const char *const file, const LuaLib libraries = NoLibs);
};

} // namespace components
} // namespace galaxy

#endif // GALAXY_COMPONENTS_GUISCRIPT_H
