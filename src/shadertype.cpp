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

static_assert(gxy::begin(gxy::ShaderType()) << types.size() == gxy::end(gxy::ShaderType()), "");

} // unnamed namespace

namespace gxy {

const bool operator &(const ShaderType &lhs, const ShaderType &rhs)
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
  auto index = base_cast<2, 10>(static_cast<int>(type));
  assert(index < sizeof(types) / sizeof(types[0]));

  out << types[index];
  return out;
}

unknown_shader::unknown_shader(const ShaderType &type) :
  std::runtime_error(std::string("Unknown ShaderType: " + boost::lexical_cast<std::string>(type)))
{
}

} // namespace gxy

namespace YAML {

Node convert<gxy::ShaderType>::encode(const gxy::ShaderType &type)
{
  return Node(static_cast<int>(type));
}

bool convert<gxy::ShaderType>::decode(const Node &node, gxy::ShaderType &type)
{
  std::string value = node.as<std::string>();
  if (value == "Vertex") {
    type = gxy::ShaderType::Vertex;
  } else if (value == "Geometry") {
    type = gxy::ShaderType::Geometry;
  } else if (value == "Fragment") {
    type = gxy::ShaderType::Fragment;
  } else if (value == "None") {
    type = gxy::ShaderType::None;
  } else if (value == "Basic") {
    type = gxy::ShaderType::Basic;
  } else if (value == "All") {
    type = gxy::ShaderType::All;
  } else {
    type = static_cast<gxy::ShaderType>(node.as<int>());
  }

  return true;
}

} // namespace YAML

