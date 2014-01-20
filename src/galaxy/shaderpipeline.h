#ifndef GALAXY_SHADERPIPELINE_H
#define GALAXY_SHADERPIPELINE_H

#include <vector>

#include <OpenGL/gl3.h>

namespace glxy {

enum class ShaderType;

class ShaderPipeline
{
public:
  ShaderPipeline(const char *const name, const char *const folder, const ShaderType &type);
  ~ShaderPipeline();

  const GLuint id() const;

  const GLint attribute(const char *const name);
  const GLint uniform(const char *const name);

private:
  const char *const extension(const ShaderType &type);
  const GLenum type(const ShaderType &type);

  const char *const name_;
  const GLuint program_;
};

} // namespace glxy

#endif // GALAXY_SHADERPIPELINE_H
