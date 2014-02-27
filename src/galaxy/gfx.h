#ifndef GALAXY_GL_H
#define GALAXY_GL_H

#include <GLXW/glxw.h>

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

namespace gxy {
namespace gfx {

// A:
// B:
// C:
inline void clear(GLbitfield mask);
inline void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
inline void compileShader(GLuint shader);
inline GLuint createShader(GLenum type);
// D:
// E:
// F:
// G:
inline const GLubyte *getString(GLenum name);
// H:
// I:
// J:
// K:
// L:
// M:
// N:
// O:
// P:
// Q:
// R:
// S:
inline void shaderSource(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length);
// T:
// U:
// V:
// W:
// X:
// Y:
// Z:

} // namespace gfx
} // namespace gxy

#include "gfx.ipp"
#endif // GALAXY_GL_H
