#ifndef GALAXY_COMPONENTS_GUISCRIPT_H
#define GALAXY_COMPONENTS_GUISCRIPT_H

#include <memory>
#include <vector>

#include "../component.h"
#include "../luastate.h"

#include "../gui/widget.h"

namespace gxy {
namespace components {

class GuiScript final : public Component
{
public:
  GuiScript(const char *const file);
  GuiScript(const char *const file, const LuaState::Libraries libraries);

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

  // Drawing API:
  void drawLabel(const uint32_t x, const uint32_t y, const char *const text);

private:
  LuaState state_;
  std::vector<std::shared_ptr<gui::Widget>> widgets_;
};

} // namespace components
} // namespace gxy

#endif // GALAXY_COMPONENTS_GUISCRIPT_H
