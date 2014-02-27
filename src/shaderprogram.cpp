#include "shaderprogram.h"

#include "game.h"
#include "gfx.h"
#include "logger.h"
#include "shader.h"
#include "shadertype.h"

namespace {

const char *const to_file_ext(const gxy::ShaderType &type)
{
  using gxy::ShaderType;

  switch(type) {
    case ShaderType::Vertex: return ".vert";
    case ShaderType::Fragment: return ".frag";
    case ShaderType::Geometry: return ".geom";

    default: throw gxy::unknown_shader(type); 
  }
}

const GLenum to_glenum(const gxy::ShaderType &type)
{
  using gxy::ShaderType;

  switch(type) {
    case ShaderType::Vertex: return GL_VERTEX_SHADER;
    case ShaderType::Fragment: return GL_FRAGMENT_SHADER;
    case ShaderType::Geometry: return GL_GEOMETRY_SHADER;

    default: throw gxy::unknown_shader(type); 
  }
}

} // unnamed namespace

namespace gxy {

ShaderProgram::ShaderProgram(const char *const name, const char *const folder, const ShaderType &types) :
  name_(name), program_(gfx::createProgram())
{
  std::string path(myGame()->assets());
  path += folder;

  assert(path.back() == '/' || path.back() == '\\');
  path += name;

  for (const auto& shader_type : ShaderType()) {
    if (types & shader_type) {
      std::string file = path + to_file_ext(shader_type);

      Shader shader(file, to_glenum(shader_type));
      gfx::attachShader(program_, shader.id());
    }
  }

  gfx::linkProgram(program_);
}

} // namespace gxy
