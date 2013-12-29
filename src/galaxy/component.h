#ifndef GALAXY_COMPONENT_H
#define GALAXY_COMPONENT_H

#include <chrono>

namespace galaxy {

class Component
{
public:
  Component();
  ~Component();

  virtual void update(const std::chrono::nanoseconds &dt) = 0;
  virtual void render(const std::chrono::nanoseconds &dt) = 0;
};

} // namespace galaxy

#endif // GALAXY_COMPONENT_H