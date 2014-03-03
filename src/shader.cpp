#include "shader.h"

#include <cassert>
#include <fstream>
#include <vector>

#include "logger.h"

namespace gxy {

Shader::Shader(const std::string &file, const GLenum type) : 
  shader_(gfx::createShader(type))
{
  std::ifstream in(file);
  assert(in.is_open());

  std::string line, source;
  while(std::getline(in, line)) {
    source += line + "\n";
  }

  {
    const GLchar *const data = source.c_str();
    gfx::shaderSource(shader_, 1, &data, 0);
    gfx::compileShader(shader_);
  }
}

  GLuint Shader::id() const
{
  return shader_;
}

} // namespace gxy
