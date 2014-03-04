#ifndef GALAXY_COMPONENT_H
#define GALAXY_COMPONENT_H

#include <chrono>

#include "components.h"
#include "mixins/gameable.h"

namespace gxy {

class Game;

class Component : public mixins::Gameable
{
public:
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
