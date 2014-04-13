#include "gfx.h"

namespace gxy {

template <typename T>
int ShaderProgram::setUniform(const std::string &key, const T &value)
{
  int location = gfx::getUniformLocation(program_, key.c_str());
  gfx::uniform(location, value);

  return location;
}

} // namespace gxy
