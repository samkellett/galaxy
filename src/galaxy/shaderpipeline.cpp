#include "shaderpipeline.h"

#include "game.h"
#include "logger.h"
#include "shader.h"
#include "shadertype.h"

namespace glxy {

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

  glLinkProgram(program_);
  {
    GLint ret = GL_FALSE;
    glGetProgramiv(program_, GL_LINK_STATUS, &ret);
    if (ret == GL_FALSE) {
      GLint log_length = 0;
      glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &log_length);
      char* log = (char*)malloc(log_length);
      glGetProgramInfoLog(program_, log_length, NULL, log);
      LOG(ERROR) << log;
      free(log);
    }
  }
}

ShaderPipeline::~ShaderPipeline()
{
}

const GLuint ShaderPipeline::id() const
{
  return program_;
}

const GLint ShaderPipeline::attribute(const char *const name)
{
  const GLint location = glGetAttribLocation(program_, name);
  assert(location != -1);

  return location;
}

const GLint ShaderPipeline::uniform(const char *const name)
{
  const GLint location = glGetUniformLocation(program_, name);
  assert(location != -1);

  return location;
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

} // namespace glxy
