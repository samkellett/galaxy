#include "shader.h"

#include <cassert>
#include <fstream>
#include <vector>

#include "logger.h"

namespace glxy {

Shader::Shader(const std::string &file, const GLenum type) : 
  shader_(gl::createShader(type))
{
  std::ifstream in(file);
  assert(in.is_open());

  std::string line, source;
  while(std::getline(in, line)) {
    source += line + "\n";
  }

  {
    const GLint length = source.size();
    const GLchar *const data = source.c_str();
    gl::shaderSource(shader_, 1, &data, &length);
    gl::compileShader(shader_);
  }
}

Shader::~Shader()
{
}

const GLuint Shader::id() const
{
  return shader_;
}

} // namespace glxy
