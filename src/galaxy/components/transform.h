#ifndef GALAXY_COMPONENTS_TRANSFORM_H
#define GALAXY_COMPONENTS_TRANSFORM_H

#include "../component.h"

#include <glm/glm.hpp>

namespace galaxy {
namespace components {

class Transform : public Component
{
public:
  struct Data
  {
    Data(const glm::vec3 &position, const glm::vec3 &rotation = glm::vec3(0, 0, 0), const glm::vec3 &scale = glm::vec3(1, 1, 1));

    const glm::vec3 position_;
    const glm::vec3 rotation_;
    const glm::vec3 scale_;
  };

  Transform();
  Transform(const Data &data);
  ~Transform();

  void update(const std::chrono::nanoseconds &dt);
  void render(const std::chrono::nanoseconds &dt);

  const glm::vec3 &position() const;
  const glm::vec3 &rotation() const;
  const glm::vec3 &scale() const;

private:
  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_;
};

} // namespace component
} // namespace galaxy

#endif // GALAXY_COMPONENTS_TRANSFORM_H
