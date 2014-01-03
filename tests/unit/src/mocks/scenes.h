#include "gmock/gmock.h"

#include "galaxy/scene.h"

namespace unit {
namespace mocks {

class FirstScene : public galaxy::Scene
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD1(update, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD1(render, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD0(destroy, void());
};

class SecondScene : public galaxy::Scene
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD1(update, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD1(render, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD0(destroy, void());
};

class LastScene : public galaxy::Scene
{
  MOCK_METHOD0(init, void());
  MOCK_METHOD1(update, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD1(render, void(const std::chrono::nanoseconds &dt));
  MOCK_METHOD0(destroy, void());
};

} // namesapce mocks
} // namespace unit
