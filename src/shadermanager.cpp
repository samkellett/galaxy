#include "shadermanager.h"

#include <boost/filesystem.hpp>

#include "game.h"
#include "logger.h"
#include "shaderprogram.h"

namespace gxy {

ShaderManager::ShaderManager(const std::shared_ptr<Game> game) : mixins::Gameable(game)
{
}

void ShaderManager::push(const std::string &name, const boost::filesystem::path &path, const ShaderType &type)
{
  auto shader = std::make_shared<ShaderProgram>(game(), name, path, type);
  insert({name, shader});
}

} // namespace gxy
