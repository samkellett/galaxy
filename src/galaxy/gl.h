#ifndef GALAXY_GL_H
#define GALAXY_GL_H

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <cassert>

#include "logger.h"

namespace glxy {
namespace gl {

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
  assert(glGetError() == GL_NO_ERROR);
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

  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if(status == GL_FALSE) {
    char message[1024];

    int size;
    glGetShaderInfoLog(shader, 1024, &size, message);

    LOG(ERROR) << "Could not compile shader, error:";
    LOG(ERROR) << message;
    assert(status != GL_FALSE);
  }  
}

} // namespace gl
} // namespace glxy

#endif // GALAXY_GL_H
