#ifndef GALAXY_GAMESTATE_H
#define GALAXY_GAMESTATE_H

namespace galaxy {

class GameState
{
public:
  GameState();
  ~GameState();

  virtual void init() = 0;
  virtual void update(const std::chrono::nanoseconds &dt) = 0;
  virtual void render(const std::chrono::nanoseconds &dt) = 0;
  virtual void destroy() = 0;
};

} // namespace galaxy

#endif