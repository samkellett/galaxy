#ifndef GALAXY_COMPONENT_LUASCRIPT_H
#define GALAXY_COMPONENT_LUASCRIPT_H

#include <stdio.h>

#include "../component.h"

class lua_State;

namespace galaxy {
namespace components {

class LuaScript : public Component
{
public:
  LuaScript();
  ~LuaScript();

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

private:
  lua_State *state_;
  FILE *script_;
};

} // namespace component
} // namespace galaxy

#endif // GALAXY_COMPONENT_LUASCRIPT_H