#ifndef GALAXY_SHADERMANAGER_H
#define GALAXY_SHADERMANAGER_H

#include <map>
#include <memory>
#include <string>

#include "shaderprogram.h"

namespace gxy {

enum class ShaderType;

class ShaderManager
{
public:
  ShaderManager();
  ~ShaderManager();

  void push(const std::string &name, const char *const path, const ShaderType &type);
  const std::shared_ptr<ShaderProgram> at(const std::string &key);

private:
  std::map<std::string, std::shared_ptr<ShaderProgram>> shaders_;
};

} // namespace gxy

#endif // GALAXY_SHADERMANAGER_H
