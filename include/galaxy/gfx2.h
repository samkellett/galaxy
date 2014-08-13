#ifndef GALAXY_GFX_H
#define GALAXY_GFX_H

#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>

#if defined(__linux) && !defined(__APPLE__)
  #include <GLXW/glxw.h>
#endif

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "gfx2_macros.h"

namespace gxy {
namespace gfx {

inline const char *getErrorString(GLenum error)
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

// A:
GXY_GFX_METHOD(a,ttachShader)
// B:
GXY_GFX_METHOD(b,indBuffer)
GXY_GFX_METHOD(b,indTexture)
GXY_GFX_METHOD(b,indVertexArray)
GXY_GFX_METHOD(b,lendFunc)
GXY_GFX_METHOD(b,ufferData)
// C:
GXY_GFX_METHOD(c,lear)
GXY_GFX_METHOD(c,learColor)
GXY_GFX_METHOD(c,ompileShader)
GXY_GFX_METHOD(GLuint, c,reateProgram)
GXY_GFX_METHOD(GLuint, c,reateShader)
// D:
GXY_GFX_METHOD(d,eleteBuffers)
GXY_GFX_METHOD(d,eleteProgram)
GXY_GFX_METHOD(d,eleteSamplers)
GXY_GFX_METHOD(d,eleteTextures)
GXY_GFX_METHOD(d,isable)
GXY_GFX_METHOD(d,isableVertexAttribArray)
GXY_GFX_METHOD(d,rawArrays)
// E:
GXY_GFX_METHOD(e,nable)
GXY_GFX_METHOD(e,nableVertexAttribArray)
// F:
// G:
GXY_GFX_METHOD(g,enBuffers)
GXY_GFX_METHOD(g,enerateMipmap)
GXY_GFX_METHOD(g,enSamplers)
GXY_GFX_METHOD(g,enTextures)
GXY_GFX_METHOD(g,enVertexArrays)
GXY_GFX_METHOD(GLint, g,etAttribLocation)
GXY_GFX_METHOD(const GLubyte *, g,etString)
GXY_GFX_METHOD(GLint, g,etUniformLocation)
// H:
// I:
// J:
// K:
// L:
GXY_GFX_METHOD(l,inkProgram)
// M:
GXY_GFX_METHOD(void *, m,apBuffer)
GXY_GFX_METHOD(void *, m,apBufferRange)
// N:
// O:
// P:
// Q:
// R:
// S:
GXY_GFX_METHOD(s,amplerParameter)
GXY_GFX_METHOD(s,haderSource)
// T:
GXY_GFX_METHOD(t,exImage2D)
// U:
// inline void uniform(GLint location, const GLfloat &value);
// inline void uniform(GLint location, const GLint &value);
// inline void uniform(GLint location, const GLuint &value);
// inline void uniform(GLint location, const glm::vec2 &value);
// inline void uniform(GLint location, const glm::vec3 &value);
// inline void uniform(GLint location, const glm::vec4 &value);
// inline void uniform(GLint location, const glm::mat3 &value);
// inline void uniform(GLint location, const glm::mat4 &value);
GXY_GFX_METHOD(bool, u,nmapBuffer)
GXY_GFX_METHOD(u,seProgram)
// // V:
GXY_GFX_METHOD(v,ertexAttribPointer)
// // W:
// // X:
// // Y:
// // Z:

} // namespace gfx
} // namespace gxy

// Include macros again to unset them
#include "gfx2_macros.h"

#endif // GALAXY_GFX_H
