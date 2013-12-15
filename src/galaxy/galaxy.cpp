#include "galaxy.h"

#include <GLFW/glfw3.h>

#include "game.h"

namespace galaxy {

Galaxy::Galaxy(Game &game) :
  game_(game)
{
  LOG(INFO) << "Initialising Galaxy";
}

Galaxy::~Galaxy()
{
}

int Galaxy::exec()
{
  GLFWwindow *window = nullptr;
  if (!glfwInit()) {
    LOG(ERROR) << "Failed to initialise GLFW.";
    return 1;
  }
  
  window = glfwCreateWindow(game_.width(), game_.height(), game_.title(), nullptr, nullptr);
  LOG(INFO) << "Window: " << window;
  if (!window) {
    LOG(ERROR) << "Could not create a GLFW window.";
    glfwTerminate();
    return 1;
  }
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwMakeContextCurrent(window);

  LOG(INFO) << "Beginning game loop";  
  while(!glfwWindowShouldClose(window)) {
    // rendering
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  LOG(INFO) << "Exited game loop";

  glfwTerminate();
  return 0;
}
  
} // namespace galaxy
