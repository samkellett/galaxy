#include "shadertype.h"

namespace gxy {

const bool operator &(const ShaderType &lhs, const ShaderType &rhs)
{
  return static_cast<int>(lhs) & static_cast<int>(rhs);
}

ShaderType operator ++(ShaderType& type)
{
  return type = static_cast<ShaderType>(static_cast<int>(type) << 1);
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
  return ShaderType(static_cast<int>(ShaderType::Fragment) << 1);
}

} // namespace gxy
