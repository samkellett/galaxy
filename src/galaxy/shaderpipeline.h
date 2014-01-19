#ifndef GALAXY_SHADERPIPELINE_H
#define GALAXY_SHADERPIPELINE_H

namespace galaxy {

enum class ShaderType;

class ShaderPipeline
{
public:
  ShaderPipeline(const char *const name, const char *const path, const ShaderType &type);
  ~ShaderPipeline();
};

} // namespace galaxy

#endif // GALAXY_SHADERPIPELINE_H
