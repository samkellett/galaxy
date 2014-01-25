#ifndef GALAXY_SHADERPROGRAM_H
#define GALAXY_SHADERPROGRAM_H

#include <vector>

#include "gfx.h"

namespace gxy {

enum class ShaderType;

class ShaderProgram final
{
public:
  ShaderProgram(const char *const name, const char *const folder, const ShaderType &type);
  ShaderProgram(const ShaderProgram &) = delete;
  ShaderProgram &operator =(ShaderProgram) = delete;

private:
  const char *const extension(const ShaderType &type);
  const GLenum type(const ShaderType &type);

  const char *const name_;
  const GLuint program_;
};

} // namespace gxy

#endif // GALAXY_SHADERPROGRAM_H
