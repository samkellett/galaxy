#ifndef GALAXY_COMPONENT_H
#define GALAXY_COMPONENT_H

#include <chrono>

#include "components.h"

namespace glxy {

class Component
{
public:
  ~Component();

  virtual void update(const std::chrono::nanoseconds &dt) = 0;
  virtual void render(const std::chrono::nanoseconds &dt) = 0;

  const ComponentType type() const;

protected:
  Component(const ComponentType type);

private:
  const ComponentType type_;
};

} // namespace glxy

#endif // GALAXY_COMPONENT_H
