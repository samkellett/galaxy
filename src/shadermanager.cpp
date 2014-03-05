#include "shadermanager.h"

#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

#include "game.h"
#include "logger.h"
#include "shaderprogram.h"
#include "shadertype.h"

namespace gxy {

ShaderManager::ShaderManager(const std::shared_ptr<Game> game) : mixins::Gameable(game)
{
}

void ShaderManager::push(const YAML::Node &data)
{
  auto name = data["name"].as<std::string>();
  boost::filesystem::path path(data["path"].as<std::string>());
  auto type = data["type"].as<ShaderType>();

  LOG(INFO) << "Adding shader: " << name << " (" << data["type"].as<std::string>() << "), at: " << path;

  auto shader = std::make_shared<ShaderProgram>(game(), name, path, type);
  insert({name, shader});
}

} // namespace gxy
