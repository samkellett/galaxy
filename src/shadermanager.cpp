#include "shadermanager.h"

#include "logger.h"
#include "shaderprogram.h"

namespace gxy {

void ShaderManager::push(const std::string &name, const char *const path, const ShaderType &type)
{
  auto shader = std::make_shared<ShaderProgram>(name.c_str(), path, type);
  insert({name, shader});
}

};
