#ifndef GALAXY_SHADERTYPE_H
#define GALAXY_SHADERTYPE_H

namespace gxy {

enum class ShaderType
{
  Vertex = 0x1,
  Geometry = 0x2,
  Fragment = 0x4,

  None = 0,
  Basic = Vertex | Fragment,
  All = Vertex | Geometry | Fragment
};

const bool operator &(const ShaderType &lhs, const ShaderType &rhs);

ShaderType operator ++(ShaderType& type);
ShaderType operator *(ShaderType type);
ShaderType begin(const ShaderType &);
ShaderType end(const ShaderType &);

} // namespace gxy

#endif // GALAXY_SHADERTYPE_H
