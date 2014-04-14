#ifndef GALAXY_GFX_H
#define GALAXY_GFX_H

#if defined(__linux) && !defined(__APPLE__)
  #include <GLXW/glxw.h>
#endif

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace gxy {
namespace gfx {

// A:
inline void attachShader(GLuint program, GLuint shader);
// B:
inline void bindBuffer(GLenum target, GLuint buffer);
inline void bindTexture(GLenum target, GLuint texture);
inline void blendFunc(GLenum sfactor, GLenum dfactor);
inline void bufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
// C:
inline void clear(GLbitfield mask);
inline void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
inline void compileShader(GLuint shader);
inline GLuint createProgram();
inline GLuint createShader(GLenum type);
// D:
inline void deleteBuffers(GLsizei n, const GLuint *buffers);
inline void deleteProgram(GLuint program);
inline void deleteSamplers(GLsizei n, const GLuint *samplers);
inline void deleteTextures(GLsizei n, const GLuint *textures);
inline void disable(GLenum cap);
inline void drawArrays(GLenum mode, GLint first, GLsizei count);
// E:
inline void enable(GLenum cap);
// F:
// G:
inline void genBuffers(GLsizei n, GLuint *buffers);
inline void generateMipmap(GLenum target);
inline void genSamplers(GLsizei n, GLuint *samplers);
inline void genTextures(GLsizei n, GLuint *textures);
inline GLint getAttribLocation(GLuint program, const GLchar *name);
inline const GLubyte *getString(GLenum name);
inline GLint getUniformLocation(GLuint program, const GLchar *name);
// H:
// I:
// J:
// K:
// L:
inline void linkProgram(GLuint program);
// M:
inline void *mapBuffer(GLenum target, GLenum access);
inline void *mapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
// N:
// O:
// P:
// Q:
// R:
// S:
inline void samplerParameter(GLuint sampler, GLenum pname, GLint param);
inline void shaderSource(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length);
// T:
inline void texImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data);
// U:
inline void uniform(GLint location, const GLfloat &value);
inline void uniform(GLint location, const GLint &value);
inline void uniform(GLint location, const GLuint &value);
inline void uniform(GLint location, const glm::vec2 &value);
inline void uniform(GLint location, const glm::vec3 &value);
inline void uniform(GLint location, const glm::vec4 &value);
inline void uniform(GLint location, const glm::mat3 &value);
inline void uniform(GLint location, const glm::mat4 &value);
inline bool unmapBuffer(GLenum target);
inline void useProgram(GLuint program);
// V:
// W:
// X:
// Y:
// Z:

} // namespace gfx
} // namespace gxy

#include "gfx.hpp"
#endif // GALAXY_GFX_H
