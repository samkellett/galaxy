#include "shadermanager.h"

#include "logger.h"

namespace glxy {

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

void ShaderManager::push(const std::string &name, const char *const path, const ShaderType &type)
{
  auto shader = std::make_shared<ShaderPipeline>(name.c_str(), path, type);
  shaders_.insert({name, shader});
}

const std::shared_ptr<ShaderPipeline> ShaderManager::at(const std::string &key)
{
  return shaders_.at(key);
}

};
