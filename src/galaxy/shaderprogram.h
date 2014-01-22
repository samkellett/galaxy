#ifndef GALAXY_SHADERPROGRAM_H
#define GALAXY_SHADERPROGRAM_H

#include <vector>

#include "gl.h"

namespace gxy {

enum class ShaderType;

class ShaderProgram
{
public:
  ShaderProgram(const char *const name, const char *const folder, const ShaderType &type);
  ~ShaderProgram();

  const GLuint id() const;

  const GLint attribute(const char *const name);
  const GLint uniform(const char *const name);

private:
  const char *const extension(const ShaderType &type);
  const GLenum type(const ShaderType &type);

  const char *const name_;
  const GLuint program_;
};

} // namespace gxy

#endif // GALAXY_SHADERPROGRAM_H
