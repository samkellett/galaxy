#ifndef GALAXY_SHADERMANAGER_H
#define GALAXY_SHADERMANAGER_H

#include <map>
#include <memory>
#include <string>

#include "mixins/gameable.h"

namespace YAML { class Node; }

namespace gxy {

class ShaderProgram;
enum class ShaderType;

typedef std::map<std::string, std::shared_ptr<ShaderProgram>> ShaderMap;
class ShaderManager final : private ShaderMap, mixins::Gameable
{
public:
  ShaderManager() = delete;
  ShaderManager(Game &game);
  ShaderManager(const ShaderManager &) = delete;
  ShaderManager &operator =(ShaderManager) = delete;

  using ShaderMap::at;
  using ShaderMap::empty;

  void push(const YAML::Node &data);
};

} // namespace gxy

#endif // GALAXY_SHADERMANAGER_H
