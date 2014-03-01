#ifndef GALAXY_SHADERPROGRAM_H
#define GALAXY_SHADERPROGRAM_H

#include <string>
#include <vector>

namespace boost { namespace filesystem { class path; }}

namespace gxy {

enum class ShaderType;

class ShaderProgram final
{
public:
  ShaderProgram(const std::string &name, const boost::filesystem::path &folder, const ShaderType &type);
  ShaderProgram(const ShaderProgram &) = delete;
  ShaderProgram &operator =(ShaderProgram) = delete;

private:
  const std::string name_;
  const unsigned int program_;
};

} // namespace gxy

#endif // GALAXY_SHADERPROGRAM_H
