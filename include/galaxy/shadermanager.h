#ifndef GALAXY_SHADERMANAGER_H
#define GALAXY_SHADERMANAGER_H

#include <map>
#include <memory>
#include <string>

namespace boost { namespace filesystem { class path; }}

namespace gxy {

class ShaderProgram;
enum class ShaderType;

typedef std::map<std::string, std::shared_ptr<ShaderProgram>> ShaderMap;
class ShaderManager final : private ShaderMap
{
public:
  ShaderManager() = default;
  ShaderManager(const ShaderManager &) = delete;
  ShaderManager &operator =(ShaderManager) = delete;

  using ShaderMap::at;
  using ShaderMap::empty;

  void push(const std::string &name, const boost::filesystem::path &path, const ShaderType &type);
};

} // namespace gxy

#endif // GALAXY_SHADERMANAGER_H
