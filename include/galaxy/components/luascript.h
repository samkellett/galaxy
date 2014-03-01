#ifndef GALAXY_COMPONENT_LUASCRIPT_H
#define GALAXY_COMPONENT_LUASCRIPT_H

#include <string>

#include "component.h"
#include "luastate.h"

namespace gxy {
namespace components {

class LuaScript : public Component
{
public:
  LuaScript(const std::string &file);
  LuaScript(const std::string &file, const LuaState::Libraries libraries);

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

protected:
  LuaState state_;
};

} // namespace component
} // namespace gxy

#endif // GALAXY_COMPONENT_LUASCRIPT_H
