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
  struct Data
  {
    Data(const char *script);

    const char *script_;
  };

  LuaScript(const char *const file = "");
  LuaScript(const Data &data);
  ~LuaScript();

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

private:
  lua_State *state_;
  const char *script_;

  bool has_update_;
};

} // namespace component
} // namespace galaxy

#endif // GALAXY_COMPONENT_LUASCRIPT_H
