#ifndef GALAXY_SHADERPROGRAM_H
#define GALAXY_SHADERPROGRAM_H

#include <vector>

namespace gxy {

enum class ShaderType;

class ShaderProgram final
{
public:
  ShaderProgram(const char *const name, const char *const folder, const ShaderType &type);
  ShaderProgram(const ShaderProgram &) = delete;
  ShaderProgram &operator =(ShaderProgram) = delete;

private:
  const char *const name_;
  const unsigned int program_;
};

} // namespace gxy

#endif // GALAXY_SHADERPROGRAM_H
