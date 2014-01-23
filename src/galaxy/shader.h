#ifndef GALAXY_SHADER_H
#define GALAXY_SHADER_H

#include <string>

#include "gfx.h"

namespace gxy {

enum class ShaderType;

class Shader
{
public:
  Shader(const std::string &file, const GLenum type);

  const GLuint id() const;

private:
  const GLuint shader_;
};

} // namespace gxy

#endif // GALAXY_SHADER_H
