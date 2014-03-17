#ifndef GALAXY_SHADERPROGRAM_H
#define GALAXY_SHADERPROGRAM_H

#include <string>
#include <vector>

#include "mixins/gameable.h"

namespace boost { namespace filesystem { class path; }}

namespace gxy {

class Game;
enum class ShaderType;

class ShaderProgram final : public mixins::Gameable
{
public:
  ShaderProgram() = delete;
  ShaderProgram(Game &game, const std::string &name, const boost::filesystem::path &folder, const ShaderType &type);
  ShaderProgram(const ShaderProgram &) = delete;
  ShaderProgram &operator =(ShaderProgram) = delete;

private:
  const std::string name_;
  const unsigned int program_;
};

} // namespace gxy

#endif // GALAXY_SHADERPROGRAM_H
