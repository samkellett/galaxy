#include "shader.h"

#include <cassert>
#include <fstream>
#include <vector>

#include "logger.h"

namespace galaxy {

Shader::Shader(const std::string &file, const GLenum type) : 
  shader_(glCreateShader(type))
{
  std::ifstream in(file);
  assert(in.is_open());

  std::string line, source;
  while(std::getline(in, line)) {
    source += line + "\n";
  }

  const GLint length = source.size();
  const GLchar *const data = source.c_str();
  glShaderSource(shader_, 1, &data, &length);
  glCompileShader(shader_);

  {
    GLint status;
    glGetShaderiv(shader_, GL_COMPILE_STATUS, &status);
    // assert(status != GL_FALSE);
    if(status == GL_FALSE) {
      char log[1024];
      char message[1536];

      int log_length;
      glGetShaderInfoLog(shader_, 1024, &log_length, log);
      std::string shader_type;

      if (type == GL_VERTEX_SHADER) {
        shader_type = "vertex shader";
      } else if (type == GL_FRAGMENT_SHADER) {
        shader_type = "fragment shader";
      } else if (type == GL_GEOMETRY_SHADER) {
        shader_type = "geometry shader";
      } else {
        shader_type = "unknown shader type";
      }

      LOG(ERROR) << "Error in " << shader_type << "!";
      LOG(ERROR) << "The compiler returned:";
      LOG(ERROR) << log;
      // sprintf_s(message, "Error in %s!\n%s\nShader file not compiled.  The compiler returned:\n\n%s", shader_type, file.c_str(), log);
      // LOG(ERROR) << message;
      // MessageBox(NULL, message, "Error", MB_ICONERROR);
      // return;
    }
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
