#include "shadermanager.h"

#include <boost/filesystem.hpp>

#include "logger.h"
#include "shaderprogram.h"

namespace gxy {

void ShaderManager::push(const std::string &name, const boost::filesystem::path &path, const ShaderType &type)
{
  auto shader = std::make_shared<ShaderProgram>(name, path, type);
  insert({name, shader});
}

};
