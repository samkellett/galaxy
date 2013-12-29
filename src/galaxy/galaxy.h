#ifndef GALAXY_GALAXY_H
#define GALAXY_GALAXY_H

#include <GLFW/glfw3.h>

namespace galaxy {

class Game;

class Galaxy
{
public:
  Galaxy(Game &game);
  ~Galaxy();
  
  int exec();
  
private:
  GLFWwindow *window_;
  Game &game_;
};

} // namespace galaxy

#endif // GALAXY_GALAXY_H
