#include "shaderpipeline.h"

#include "game.h"
#include "logger.h"
#include "shader.h"
#include "shadertype.h"

namespace galaxy {

ShaderPipeline::ShaderPipeline(const char *const name, const char *const folder, const ShaderType &types) :
  name_(name), program_(glCreateProgram())
{
  std::string path(myGame()->assets());
  path += folder;

  assert(path.back() == '/' || path.back() == '\\');
  path += name;

  for (const auto& shader_type : ShaderType()) {
    if (types & shader_type) {
      std::string file = path + extension(shader_type);

      Shader shader(file, type(shader_type));
      glAttachShader(program_, shader.id());
    }
  }
}

ShaderPipeline::~ShaderPipeline()
{
}

const char *const ShaderPipeline::extension(const ShaderType &type)
{
  switch(type)
  {
    case ShaderType::Vertex: return ".vert";
    case ShaderType::Fragment: return ".frag";
    case ShaderType::Geometry: return ".geom";

    default: assert(false);
  }
}

const GLenum ShaderPipeline::type(const ShaderType &type)
{
  switch(type)
  {
    case ShaderType::Vertex: return GL_VERTEX_SHADER;
    case ShaderType::Fragment: return GL_FRAGMENT_SHADER;
    case ShaderType::Geometry: return GL_GEOMETRY_SHADER;

    default: assert(false);
  }
}

} // namespace galaxy
