#ifndef GALAXY_SHADERTYPE_H
#define GALAXY_SHADERTYPE_H

namespace galaxy {

enum class ShaderType
{
  Vertex = 0x1,
  Geometry = 0x2,
  Fragment = 0x4,

  Basic = Vertex | Fragment,
  All = Vertex | Geometry | Fragment
};

}

#endif // GALAXY_SHADERTYPE_H
