#include "gmock/gmock.h"

#include "galaxy/gamestate.h"

namespace unit {
namespace mocks {

class GameStateOne : public galaxy::GameState
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD1(update, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD1(render, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD0(destroy, void());
};

class GameStateTwo : public galaxy::GameState
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD1(update, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD1(render, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD0(destroy, void());
};

class GameStateThree : public galaxy::GameState
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD1(update, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD1(render, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD0(destroy, void());
};

} // namesapce mocks
} // namespace unit