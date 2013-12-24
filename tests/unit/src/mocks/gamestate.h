#include "gmock/gmock.h"

#include "galaxy/gamestate.h"

namespace unit {
namespace mocks {

class GameStateOne : public galaxy::GameState
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD0(update, void());
  MOCK_METHOD0(render, void());
  MOCK_METHOD0(destroy, void());
};

class GameStateTwo : public galaxy::GameState
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD0(update, void());
  MOCK_METHOD0(render, void());
  MOCK_METHOD0(destroy, void());
};

class GameStateThree : public galaxy::GameState
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD0(update, void());
  MOCK_METHOD0(render, void());
  MOCK_METHOD0(destroy, void());
};

} // namesapce mocks
} // namespace unit