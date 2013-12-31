#include "gamestate.h"

namespace galaxy {

GameState::GameState() : 
  objects_(std::shared_ptr<ObjectManager>(new ObjectManager))
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

const std::shared_ptr<ObjectManager> GameState::objects()
{
  return objects_;
}

} // namespace galaxy