#ifndef GALAXY_GL_H
#define GALAXY_GL_H

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

namespace gxy {
namespace gfx {

inline void clear(GLbitfield mask);
inline void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
inline void compileShader(GLuint shader);
inline GLuint createShader(GLenum type);
inline void shaderSource(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length);

} // namespace gfx
} // namespace gxy

#include "gl.ipp"
#endif // GALAXY_GL_H
