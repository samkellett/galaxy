#include "shadertype.h"

namespace glxy {

const bool operator &(const ShaderType &lhs, const ShaderType &rhs)
{
  return int(lhs) & int(rhs);
}

ShaderType operator ++(ShaderType& type)
{
  return type = static_cast<ShaderType>(int(type) << 1);
}

ShaderType operator *(ShaderType type)
{
  return type;
}

ShaderType begin(const ShaderType &)
{
  return ShaderType::Vertex;
}

ShaderType end(const ShaderType &)
{
  return ShaderType(int(ShaderType::Fragment) << 1);
}

} // namespace glxy
