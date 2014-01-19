#ifndef GALAXY_SHADERMANAGER_H
#define GALAXY_SHADERMANAGER_H

#include <map>
#include <memory>

#include "shaderpipeline.h"

namespace galaxy {

enum class ShaderType;

class ShaderManager
{
public:
  ShaderManager();
  ~ShaderManager();

  void push(const char *const name, const char *const path, const ShaderType &type);

private:
  std::map<const char *const, std::shared_ptr<ShaderPipeline>> shaders_;
};

} // namespace galaxy

#endif // GALAXY_SHADERMANAGER_H
