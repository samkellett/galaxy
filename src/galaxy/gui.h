#ifndef GALAXY_GUI_H
#define GALAXY_GUI_H

#include <cstdint>

class lua_State;

namespace galaxy {

class Gui
{
public:
  Gui(lua_State *L);
  void render();

  // Drawing API:
  void drawLabel(const uint32_t x, const uint32_t y, const char *const text);

private:
  // Pen pen_;
};

} // namespace galaxy

#endif // GALAXY_GUI_H
