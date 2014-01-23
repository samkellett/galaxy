#ifndef GALAXY_SHADERMANAGER_H
#define GALAXY_SHADERMANAGER_H

#include <map>
#include <memory>
#include <string>

#include "shaderprogram.h"

namespace gxy {

enum class ShaderType;

typedef std::map<std::string, std::shared_ptr<ShaderProgram>> ShaderMap;
class ShaderManager : private ShaderMap
{
public:
  ShaderManager() = default;

  using ShaderMap::at;

  void push(const std::string &name, const char *const path, const ShaderType &type);
};

} // namespace gxy

#endif // GALAXY_SHADERMANAGER_H
