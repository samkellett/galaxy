#include "gamestate.h"

namespace galaxy {

GameState::GameState()
{
}

GameState::~GameState()
{ 
}

void GameState::update(const std::chrono::nanoseconds &dt)
{
}

void GameState::render(const std::chrono::nanoseconds &dt)
{
}

std::vector<std::shared_ptr<GameObject>> GameState::objects()
{
  return objects_;
}

} // namespace galaxy