#ifndef GALAXY_COMPONENTS_GUISCRIPT_H
#define GALAXY_COMPONENTS_GUISCRIPT_H

#include "luascript.h"

#include "../shaderpipeline.h"

namespace galaxy {
namespace components {

class GuiScript : public LuaScript
{
public:
  GuiScript(const char *const file, const LuaLib libraries = NoLibs);

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

  // Drawing API:
  void drawLabel(const uint32_t x, const uint32_t y, const char *const text);
};

} // namespace components
} // namespace galaxy

#endif // GALAXY_COMPONENTS_GUISCRIPT_H
