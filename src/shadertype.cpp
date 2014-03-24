#include "shadertype.h"

#include <array>
#include <cassert>

#include <boost/lexical_cast.hpp>

#include "casts.h"

namespace {

std::array<const char *, 3> types {{
  "vertex",
  "geometry",
  "fragment"
}};

static_assert((gxy::begin(gxy::ShaderType()) << types.size()) == gxy::end(gxy::ShaderType()), "");

} // unnamed namespace

namespace gxy {

bool operator &(const ShaderType &lhs, const ShaderType &rhs)
{
  return static_cast<int>(lhs) & static_cast<int>(rhs);
}

ShaderType operator ++(ShaderType& type)
{
  return type = static_cast<ShaderType>(type << 1);
}

ShaderType operator *(ShaderType type)
{
  return type;
}

std::ostream &operator <<(std::ostream &out, const ShaderType &type)
{
  unsigned int index = base_cast<2, 10>(static_cast<int>(type));
  assert(index < types.size());

  out << types[index];
  return out;
}

unknown_shader::unknown_shader(const ShaderType &type) :
  std::runtime_error(std::string("Unknown ShaderType: " + boost::lexical_cast<std::string>(type)))
{
}

} // namespace gxy

namespace YAML {

typedef gxy::ShaderType ShaderType;

Node convert<ShaderType>::encode(const ShaderType &type)
{
  return Node(static_cast<int>(type));
}

bool convert<ShaderType>::decode(const Node &node, ShaderType &type)
{
  auto value = node.as<std::string>();
  if (value == "Vertex") {
    type = ShaderType::Vertex;
  } else if (value == "Geometry") {
    type = ShaderType::Geometry;
  } else if (value == "Fragment") {
    type = ShaderType::Fragment;
  } else if (value == "None") {
    type = ShaderType::None;
  } else if (value == "Basic") {
    type = ShaderType::Basic;
  } else if (value == "All") {
    type = ShaderType::All;
  } else {
    type = static_cast<ShaderType>(node.as<int>());
  }

  return true;
}

} // namespace YAML

