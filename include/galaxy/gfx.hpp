#include <cassert>

#include "logger.h"

namespace gxy {
namespace gfx {

// A:
void attachShader(GLuint program, GLuint shader)
{
  glAttachShader(program, shader);
  assert(glGetError() == GL_NO_ERROR);
}
// B:
// C:
void clear(GLbitfield mask)
{
  glClear(mask);
  assert(glGetError() == GL_NO_ERROR);
}

void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  glClearColor(red, green, blue, alpha);
  assert(glGetError() == GL_NO_ERROR);
}

void compileShader(GLuint shader)
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

GLuint createProgram()
{
  auto ret = glCreateProgram();
  assert(glGetError() == GL_NO_ERROR);

  return ret;
}

GLuint createShader(GLenum type)
{
  auto ret = glCreateShader(type);
  assert(glGetError() == GL_NO_ERROR);

  return ret;
}

// D:
// E:
// F:
// G:
const GLubyte *getString(GLenum name)
{
  auto ret = glGetString(name);
  assert(glGetError() == GL_NO_ERROR);

  return ret;
}

// H:
// I:
// J:
// K:
// L:
void linkProgram(GLuint program)
{
  glLinkProgram(program);

  GLint ret = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &ret);
  if (ret == GL_FALSE) {
    GLint log_length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
    GLchar *log = static_cast<GLchar *>(malloc(log_length));
    glGetProgramInfoLog(program, log_length, nullptr, log);

    LOG(ERROR) << log;
    free(log);
  }
}

// M:
// N:
// O:
// P:
// Q:
// R:
// S:
void shaderSource(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length)
{
  glShaderSource(shader, count, string, length);
  assert(glGetError() == GL_NO_ERROR);
}

// T:
// U:
// V:
// W:
// X:
// Y:
// Z:

} // namespace gfx
} // namespace gxy
