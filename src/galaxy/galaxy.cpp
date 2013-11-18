#include "galaxy.h"

#include <GLFW/glfw3.h>

#include "game.h"

namespace galaxy {

Galaxy::Galaxy(Game &game) :
  game_(game)
{
}

Galaxy::~Galaxy()
{
}

int32 Galaxy::exec()
{
  GLFWwindow *window = nullptr;
  if (!glfwInit()) {
    return 1;
  }
  
  window = glfwCreateWindow(640, 480, game_.title(), nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return 1;
  }
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwMakeContextCurrent(window);
  
  while(!glfwWindowShouldClose(window)) {
    // rendering
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
  
} // namespace galaxy
