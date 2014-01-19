#ifndef GALAXY_SHADERPIPELINE_H
#define GALAXY_SHADERPIPELINE_H

#include <vector>

#include <OpenGL/gl.h>

namespace galaxy {

enum class ShaderType;

class ShaderPipeline
{
public:
  ShaderPipeline(const char *const name, const char *const folder, const ShaderType &type);
  ~ShaderPipeline();

private:
  const char *const extension(const ShaderType &type);
  const GLenum type(const ShaderType &type);

  const char *const name_;
  const GLuint program_;
};

} // namespace galaxy

#endif // GALAXY_SHADERPIPELINE_H
