#include "galaxy.h"

#include <chrono>
#include <sstream>
#include <stdexcept>
#include <string>

#include <glog/logging.h>

#include "component.h"
#include "game.h"
#include "gfx.h"
#include "scene.h"

namespace gxy {

Galaxy::Galaxy(Game &game) :
  game_(game)
{
  LOG(INFO) << "Initialising Galaxy";
}

int Galaxy::exec()
{
  glfwSetErrorCallback([] (int code, const char *msg) {
    glfwTerminate();

    std::ostringstream stream;
    stream << "GLFW Error " << code << ": " << msg;

    throw std::runtime_error(stream.str());
  });

  if (glfwInit() != GL_TRUE) {
    throw std::runtime_error("Failed to initialise GLFW.");
  }
  
  if (glxwInit() != 0) {
    throw std::runtime_error("Cannot initialise GLXW.");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
//  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  LOG(INFO) << "Creating GLFW window...";
  GLFWwindow *window = glfwCreateWindow(game_.width(), game_.height(), game_.title(), nullptr, nullptr);

  glfwMakeContextCurrent(window);
  glfwSwapInterval(0);

  LOG(INFO) << "OpenGL Version: " << gfx::getString(GL_VERSION);
  LOG(INFO) << "OpenGL Vendor: " << gfx::getString(GL_VENDOR);
  LOG(INFO) << "OpenGL Renderer: " << gfx::getString(GL_RENDERER); 
  LOG(INFO) << "GLSL Version: " << gfx::getString(GL_SHADING_LANGUAGE_VERSION);
  LOG(INFO) << "GLFW Version: " << glfwGetVersionString();
  // Bee yellow
  gfx::clearColor(1.0f, 0.83f, 0.33f, 1.0f);

  // Load the first scene
  auto scene = myGame()->scenes().next();
  scene->init();
  
  LOG(INFO) << "Beginning game loop";
  std::chrono::nanoseconds dt(0);
  while(!glfwWindowShouldClose(window)) {
    auto start = std::chrono::high_resolution_clock::now();
    gfx::clear(GL_COLOR_BUFFER_BIT);

    // Components
    for (std::shared_ptr<Component> component : scene->components()) {
      component->update(dt);
      component->render(dt);
    }
    
    glfwSwapBuffers(window);
    glfwPollEvents();

    auto end = std::chrono::high_resolution_clock::now();
    dt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  }

  LOG(INFO) << "Exited game loop";
  glfwTerminate();

  return 0;
}
  
} // namespace gxy
