#include "shader.h"

#include <cassert>
#include <fstream>
#include <vector>

#include "logger.h"

namespace galaxy {

Shader::Shader(const std::string &file, const GLenum type) : 
  shader_(glCreateShader(type))
{
  std::ifstream shader(file);
  assert(shader.is_open());

  std::string line;
  std::vector<const char *> contents;
  while (std::getline(shader, line)) {
    contents.push_back(line.c_str());
  }

  glShaderSource(shader_, static_cast<int>(contents.size()), &contents[0], nullptr);
  glCompileShader(shader_);

  {
    GLint status;
    glGetShaderiv(shader_, GL_COMPILE_STATUS, &status);
    assert(status != GL_FALSE);
  }
}

Shader::~Shader()
{
}

const GLuint Shader::id() const
{
  return shader_;
}

} // namespace galaxy
