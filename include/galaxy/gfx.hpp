#include <string>

#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>

#include <glm/gtc/type_ptr.hpp>

#include "logger.h"

namespace gxy {
namespace gfx {

// A:
void attachShader(GLuint program, GLuint shader)
{
  glAttachShader(program, shader);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

// B:
void bindBuffer(GLenum target, GLuint buffer)
{
  glBindBuffer(target, buffer);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void bindTexture(GLenum target, GLuint texture)
{
  glBindTexture(target, texture);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void bindVertexArray(GLuint array)
{
  glBindVertexArray(array);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void blendFunc(GLenum sfactor, GLenum dfactor)
{
  glBlendFunc(sfactor, dfactor);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void bufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
  glBufferData(target, size, data, usage);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

// C:
void clear(GLbitfield mask)
{
  glClear(mask);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  glClearColor(red, green, blue, alpha);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
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
    BOOST_ASSERT(status != GL_FALSE);
  }
}

GLuint createProgram()
{
  auto ret = glCreateProgram();
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

  return ret;
}

GLuint createShader(GLenum type)
{
  auto ret = glCreateShader(type);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

  return ret;
}

// D:
void deleteBuffers(GLsizei n, const GLuint *buffers)
{
  glDeleteBuffers(n, buffers);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void deleteProgram(GLuint program)
{
  glDeleteProgram(program);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void deleteSamplers(GLsizei n, const GLuint *samplers)
{
  glDeleteSamplers(n, samplers);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void deleteTextures(GLsizei n, const GLuint *textures)
{
  glDeleteTextures(n, textures);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void disable(GLenum cap)
{
  glDisable(cap);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void disableVertexAttribArray(GLuint index)
{
  glDisableVertexAttribArray(index);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void drawArrays(GLenum mode, GLint first, GLsizei count)
{
  glDrawArrays(mode, first, count);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

// E:
void enable(GLenum cap)
{
  glEnable(cap);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void enableVertexAttribArray(GLuint index)
{
  glEnableVertexAttribArray(index);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

// F:
// G:
void genBuffers(GLsizei n, GLuint *buffers)
{
  glGenBuffers(n, buffers);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void generateMipmap(GLenum target)
{
  glGenerateMipmap(target);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void genSamplers(GLsizei n, GLuint *samplers)
{
  glGenSamplers(n, samplers);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void genTextures(GLsizei n, GLuint *textures)
{
  glGenTextures(n, textures);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void genVertexArrays(GLsizei n, GLuint *arrays)
{
  glGenVertexArrays(n, arrays);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

GLint getAttribLocation(GLuint program, const GLchar *name)
{
  auto ret = glGetAttribLocation(program, name);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

  return ret;
}

const char *getErrorString(GLenum error)
{
  switch(error) {
    case GL_NO_ERROR: return "NO_ERROR";
    case GL_INVALID_ENUM: return "INVALID_ENUM";
    case GL_INVALID_VALUE: return "INVALID_VALUE";
    case GL_INVALID_OPERATION: return "INVALID_OPERATION";
    case GL_INVALID_FRAMEBUFFER_OPERATION: return "INVALID_FRAMEBUFFER_OPERATION";
    case GL_OUT_OF_MEMORY: return "OUT_OF_MEMORY";
    // case GL_STACK_UNDERFLOW: return "STACK_UNDERFLOW";
    // case GL_STACK_OVERFLOW: return "STACK_OVERFLOW";
    default: return boost::lexical_cast<std::string>(error).c_str();
  }
}

const GLubyte *getString(GLenum name)
{
  auto ret = glGetString(name);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

  return ret;
}

GLint getUniformLocation(GLuint program, const GLchar *name)
{
  auto ret = glGetUniformLocation(program, name);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

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
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

  return ret;
}

void *mapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
  auto ret = glMapBufferRange(target, offset, length, access);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

  return ret;
}

// N:
// O:
// P:
// Q:
// R:
// S:
void samplerParameter(GLuint sampler, GLenum pname, GLint param)
{
  glSamplerParameteri(sampler, pname, param);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void shaderSource(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length)
{
  glShaderSource(shader, count, string, length);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

// T:
void texImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data)
{
  glTexImage2D(target, level, internalFormat, width, height, border, format, type, data);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

// U:
void uniform(GLint location, const GLfloat &value)
{
  glUniform1f(location, value);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void uniform(GLint location, const GLint &value)
{
  glUniform1i(location, value);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void uniform(GLint location, const GLuint &value)
{
  glUniform1ui(location, value);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void uniform(GLint location, const glm::vec2 &value)
{
  glUniform2fv(location, 1, glm::value_ptr(value));
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void uniform(GLint location, const glm::vec3 &value)
{
  glUniform3fv(location, 1, glm::value_ptr(value));
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void uniform(GLint location, const glm::vec4 &value)
{
  glUniform4fv(location, 1, glm::value_ptr(value));
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void uniform(GLint location, const glm::mat3 &value)
{
  glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

void uniform(GLint location, const glm::mat4 &value)
{
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

bool unmapBuffer(GLenum target)
{
  auto ret = glUnmapBuffer(target);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));

  return ret;
}

void useProgram(GLuint program)
{
  glUseProgram(program);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}

// V:
void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
  auto error = glGetError();
  BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error));
}
// W:
// X:
// Y:
// Z:

} // namespace gfx
} // namespace gxy
