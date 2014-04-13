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
void bindBuffer(GLenum target, GLuint buffer)
{
  glBindBuffer(target, buffer);
  assert(glGetError() == GL_NO_ERROR);
}

void bindTexture(GLenum target, GLuint texture)
{
  glBindTexture(target, texture);
  assert(glGetError() == GL_NO_ERROR);
}

void blendFunc(GLenum sfactor, GLenum dfactor)
{
  glBlendFunc(sfactor, dfactor);
  assert(glGetError() == GL_NO_ERROR);
}

void bufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
  glBufferData(target, size, data, usage);
  assert(glGetError() == GL_NO_ERROR);
}

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
void deleteBuffers(GLsizei n, const GLuint *buffers)
{
  glDeleteBuffers(n, buffers);
  assert(glGetError() == GL_NO_ERROR);
}

void deleteSamplers(GLsizei n, const GLuint *samplers)
{
  glDeleteSamplers(n, samplers);
  assert(glGetError() == GL_NO_ERROR);
}

void deleteTextures(GLsizei n, const GLuint *textures)
{
  glDeleteTextures(n, textures);
  assert(glGetError() == GL_NO_ERROR);
}

void disable(GLenum cap)
{
  glDisable(cap);
  assert(glGetError() == GL_NO_ERROR);
}

void drawArrays(GLenum mode, GLint first, GLsizei count)
{
  glDrawArrays(mode, first, count);
  assert(glGetError() == GL_NO_ERROR);
}

// E:
void enable(GLenum cap)
{
  glEnable(cap);
  assert(glGetError() == GL_NO_ERROR);
}

// F:
// G:
void genBuffers(GLsizei n, GLuint *buffers)
{
  glGenBuffers(n, buffers);
  assert(glGetError() == GL_NO_ERROR);
}

void generateMipmap(GLenum target)
{
  glGenerateMipmap(target);
  assert(glGetError() == GL_NO_ERROR);
}

void genSamplers(GLsizei n, GLuint *samplers)
{
  glGenSamplers(n, samplers);
  assert(glGetError() == GL_NO_ERROR);
}

void genTextures(GLsizei n, GLuint *textures)
{
  glGenTextures(n, textures);
  assert(glGetError() == GL_NO_ERROR);
}

const GLubyte *getString(GLenum name)
{
  auto ret = glGetString(name);
  assert(glGetError() == GL_NO_ERROR);

  return ret;
}

GLint getUniformLocation(GLuint program, const GLchar *name)
{
  auto ret = glGetUniformLocation(program, name);
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
    GLchar *message = new GLchar(log_length);
    glGetProgramInfoLog(program, log_length, nullptr, message);

    LOG(ERROR) << message;
    delete message;
  }
}

// M:
void *mapBuffer(GLenum target, GLenum access)
{
  auto ret = glMapBuffer(target, access);
  assert(glGetError() == GL_NO_ERROR);

  return ret;
}

void *mapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
  auto ret = glMapBufferRange(target, offset, length, access);
  assert(glGetError() == GL_NO_ERROR);

  return ret;
}

// N:
// O:
// P:
// Q:
// R:
// S:
void sampleParameter(GLuint sampler, GLenum pname, GLint param)
{
  glSampleParameteri(sampler, pname, param);
  assert(glGetError() == GL_NO_ERROR);
}

void shaderSource(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length)
{
  glShaderSource(shader, count, string, length);
  assert(glGetError() == GL_NO_ERROR);
}

// T:
void texImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data)
{
  glTexImage2D(target, level, internalFormat, width, height, border, format, type, data);
  assert(glGetError() == GL_NO_ERROR);
}

// U:
template <GLfloat>
void uniform(GLint location, const GLfloat &value)
{
  glUniform1f(location, value);
  assert(glGetError() == GL_NO_ERROR);
}

template <GLint>
void uniform(GLint location, const GLint &value)
{
  glUniform1i(location, value);
  assert(glGetError() == GL_NO_ERROR);
}

template <GLuint>
void uniform(GLint location, const GLuint &value)
{
  glUniform1ui(location, value);
  assert(glGetError() == GL_NO_ERROR);
}

template <glm::vec2>
void uniform(GLint location, const glm::vec2 &value)
{
  glUniform2fv(location, glm::value_ptr(value));
  assert(glGetError() == GL_NO_ERROR);
}

template <glm::vec3>
void uniform(GLint location, const glm::vec3 &value)
{
  glUniform3fv(location, glm::value_ptr(value));
  assert(glGetError() == GL_NO_ERROR);
}

template <glm::vec4>
void uniform(GLint location, const glm::vec4 &value)
{
  glUniform4fv(location, glm::value_ptr(value));
  assert(glGetError() == GL_NO_ERROR);
}

template <glm::mat3>
void uniform(GLint location, GLboolean transpose, const glm::mat3 &value)
{
  glUniformMatrix3fv(location, transpose, glm::value_ptr(value));
  assert(glGetError() == GL_NO_ERROR);
}

template <glm::mat4>
void uniform(GLint location, GLboolean transpose, const glm::mat4 &value)
{
  glUniformMatrix4fv(location, transpose, glm::value_ptr(value));
  assert(glGetError() == GL_NO_ERROR);
}

bool unmapBuffer(GLenum target)
{
  auto ret = glUnmapBuffer(target);
  assert(glGetError() == GL_NO_ERROR);

  return ret;
}

// V:
// W:
// X:
// Y:
// Z:

} // namespace gfx
} // namespace gxy
