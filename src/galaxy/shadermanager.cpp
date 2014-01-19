#include "shadermanager.h"

namespace galaxy {

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

void ShaderManager::push(const char *const name, const char *const path, const ShaderType &type)
{
  auto shader = std::make_shared<ShaderPipeline>(name, path, type);
  shaders_.insert({name, shader});
}

};
