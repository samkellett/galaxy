#include "galaxy.h"

#include <chrono>
#include <GLFW/glfw3.h>
#include <glog/logging.h>

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
  if (!glfwInit()) {
    LOG(ERROR) << "Failed to initialise GLFW.";
    return 1;
  }
  
  GLFWwindow *window = glfwCreateWindow(game_.width(), game_.height(), game_.title(), nullptr, nullptr);
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
  std::chrono::nanoseconds dt(0);
  while(!glfwWindowShouldClose(window)) {
    auto start = std::chrono::high_resolution_clock::now();

    game_.update(dt);
    game_.render(dt);
    
    glfwSwapBuffers(window);
    glfwPollEvents();

    auto end = std::chrono::high_resolution_clock::now();
    dt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  }
  LOG(INFO) << "Exited game loop";

  glfwTerminate();
  return 0;
}
  
} // namespace galaxy
