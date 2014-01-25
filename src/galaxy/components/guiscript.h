#ifndef GALAXY_COMPONENTS_GUISCRIPT_H
#define GALAXY_COMPONENTS_GUISCRIPT_H

#include "luascript.h"

#include "../shaderprogram.h"
#include "../gui/widget.h"

namespace gxy {
namespace components {

class GuiScript : public LuaScript
{
public:
  GuiScript(const char *const file, const LuaLib libraries = NoLibs);

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

  // Drawing API:
  void drawLabel(const uint32_t x, const uint32_t y, const char *const text);

private:
  std::vector<std::shared_ptr<gui::Widget>> widgets_;
};

} // namespace components
} // namespace gxy

#endif // GALAXY_COMPONENTS_GUISCRIPT_H
