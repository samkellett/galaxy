#include "galaxy.h"

#include "game.h"

namespace galaxy {

Galaxy::Galaxy(Game &game) :
  game_(game)
{
}

Galaxy::~Galaxy()
{
}

int32 Galaxy::exec()
{
  return 0;
}
  
} // namespace galaxy
