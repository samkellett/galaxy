#include <cassert>

#include "logger.h"

namespace gxy {
namespace gfx {

inline void clear(GLbitfield mask)
{
  glClear(mask);
  assert(glGetError() == GL_NO_ERROR);
}

inline void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  glClearColor(red, green, blue, alpha);
  assert(glGetError() == GL_NO_ERROR);
}

inline void compileShader(GLuint shader)
{
  glCompileShader(shader);

  GLint status = GL_TRUE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if(status == GL_FALSE) {
    GLint type = 0;
    GLint length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
    glGetShaderiv(shader, GL_SHADER_TYPE, &type);

    std::vector<GLchar> info(length);
    glGetShaderInfoLog(shader, length, &length, &info[0]);
    glDeleteShader(shader);

    if (type == GL_VERTEX_SHADER) {
      LOG(ERROR) << "In vertex shader:";
    } else if (type == GL_FRAGMENT_SHADER) {
      LOG(ERROR) << "In fragment shader:";
    } else if (type == GL_GEOMETRY_SHADER) {
      LOG(ERROR) << "In geometry shader:";
    }

    LOG(ERROR) << std::string(info.begin(), info.end());
    assert(status != GL_FALSE);
  }  
}

inline GLuint createShader(GLenum type)
{
  GLuint ret = glCreateShader(type);
  assert(glGetError() == GL_NO_ERROR);
  return ret;
}

inline void shaderSource(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length)
{
  glShaderSource(shader, count, string, length);
  assert(glGetError() == GL_NO_ERROR);
}

} // namespace gfx
} // namespace gxy
