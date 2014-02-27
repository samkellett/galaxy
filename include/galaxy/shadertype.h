#ifndef GALAXY_SHADERTYPE_H
#define GALAXY_SHADERTYPE_H

#include <ostream>
#include <stdexcept>
#include <type_traits>

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
constexpr ShaderType begin(const ShaderType &);
constexpr ShaderType end(const ShaderType &);

template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, ShaderType>::type operator <<(const ShaderType &type, const T i);

template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, ShaderType>::type operator >>(const ShaderType &type, const T i);

std::ostream &operator <<(std::ostream &out, const ShaderType &type);

// Exceptions:

struct unknown_shader : public std::runtime_error
{
  unknown_shader(const ShaderType &type);
};

} // namespace gxy

#include "shadertype.hpp"
#endif // GALAXY_SHADERTYPE_H
