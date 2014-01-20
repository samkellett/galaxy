#ifndef GALAXY_SHADERMANAGER_H
#define GALAXY_SHADERMANAGER_H

#include <map>
#include <memory>
#include <string>

#include "shaderpipeline.h"

namespace galaxy {

enum class ShaderType;

class ShaderManager
{
public:
  ShaderManager();
  ~ShaderManager();

  void push(const std::string &name, const char *const path, const ShaderType &type);
  const std::shared_ptr<ShaderPipeline> at(const std::string &key);

private:
  std::map<std::string, std::shared_ptr<ShaderPipeline>> shaders_;
};

} // namespace galaxy

#endif // GALAXY_SHADERMANAGER_H
