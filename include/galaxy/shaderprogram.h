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
  ~ShaderProgram();

  void use() const;
  unsigned int id() const;
  const std::string &name() const;

  int attribute(const std::string &name) const;

  template <typename T>
  int setUniform(const std::string &key, const T &value);

private:
  const std::string name_;
  const unsigned int program_;
};

} // namespace gxy

#include "shaderprogram.hpp"
#endif // GALAXY_SHADERPROGRAM_H
