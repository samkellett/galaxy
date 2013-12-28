#ifndef GALAXY_GAMESTATE_H
#define GALAXY_GAMESTATE_H

#include <chrono>
#include <map>

#include "components.h"

namespace galaxy {

class Component;

class GameState
{
public:
  GameState();
  ~GameState();

  virtual void init() = 0;
  virtual void update(const std::chrono::nanoseconds &dt);
  virtual void render(const std::chrono::nanoseconds &dt);
  virtual void destroy() = 0;

protected:
  std::multimap<Components, Component *> *components() const;

private:
  std::multimap<Components, Component *> components_;
};

} // namespace galaxy

#endif
