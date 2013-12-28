#ifndef GALAXY_GAMESTATE_H
#define GALAXY_GAMESTATE_H

#include <chrono>
#include <vector>

#include "gameobject.h"

namespace galaxy {

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
  typedef std::unique_ptr<GameObject> GameObjectPtr;
  std::vector<GameObjectPtr> objects() const;  

private:
  std::vector<GameObjectPtr> objects_;
};

} // namespace galaxy

#endif
