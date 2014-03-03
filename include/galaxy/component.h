#ifndef GALAXY_COMPONENT_H
#define GALAXY_COMPONENT_H

#include <chrono>

#include "components.h"

namespace gxy {

class Component
{
public:
  Component(const Component &) = delete;
  virtual ~Component() = default;
  Component &operator =(const Component &) = delete;

  virtual void update(const std::chrono::nanoseconds &dt) = 0;
  virtual void render(const std::chrono::nanoseconds &dt) = 0;

  ComponentType type() const;

protected:
  Component(const ComponentType type);

private:
  const ComponentType type_;
};

} // namespace gxy

#endif // GALAXY_COMPONENT_H
