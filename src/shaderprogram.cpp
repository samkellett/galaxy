#include "shaderprogram.h"

#include <boost/filesystem.hpp>

#include "game.h"
#include "gfx.h"
#include "logger.h"
#include "shader.h"
#include "shadertype.h"

namespace {

std::string to_file_ext(const gxy::ShaderType &type)
{
  using gxy::ShaderType;

  switch(type) {
    case ShaderType::Vertex: return ".vert";
    case ShaderType::Fragment: return ".frag";
    case ShaderType::Geometry: return ".geom";

    default: throw gxy::unknown_shader(type);
  }
}

GLenum to_glenum(const gxy::ShaderType &type)
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

ShaderProgram::ShaderProgram(const std::shared_ptr<Game> g, const std::string &name, const boost::filesystem::path &folder, const ShaderType &types) : mixins::Gameable(g),
  name_(name),
  program_(gfx::createProgram())
{
  auto path = game()->assets() / folder / name;

  for (const auto& shader_type : ShaderType()) {
    if (types & shader_type) {
      boost::filesystem::path ext(to_file_ext(shader_type));
      path.replace_extension(ext);

      Shader shader(path.string(), to_glenum(shader_type));
      gfx::attachShader(program_, shader.id());
    }
  }

  gfx::linkProgram(program_);
}

} // namespace gxy
