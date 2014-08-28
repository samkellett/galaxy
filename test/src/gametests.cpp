#include <chrono>
#include <thread>

#include "gtest/gtest.h"

#define GXY_MOCK_OPENGL
#include "gxy/game.h"
#include "gxy/gfx.h"
#include "gxy/macros.h"

/*

// Game loop:
gxy::game game;

game.initialise();
do {
  game.tick();
} while (!game.quitting());

*/

class GameTest : public testing::Test
{
protected:
  virtual void SetUp() {
    gxy::test::gfmap.clear();
    ASSERT_EQ(gxy::test::gfmap.empty(), 0);

    game_.initialise();
  }

  virtual void TearDown() {
    game_.teardown();
    EXPECT_EQ(gxy::test::gfmap["terminate"], 1);
  }

  gxy::game game_;
};

TEST_F(GameTest, InitGlfw) {
  using gxy::test::gfmap;

  EXPECT_EQ(gfmap["setErrorCallback"], 1);
  EXPECT_EQ(gfmap["init"], 1);

  EXPECT_EQ(gfmap["createWindow"], 1);
  EXPECT_EQ(gfmap["makeContextCurrent"], 1);
  EXPECT_EQ(gfmap["swapInterval"], 1);
}

TEST_F(GameTest, GameLoop) {
  using gxy::test::gfmap;

  const int count = 5;

  for (unsigned int i = 0; i < count; ++i) {
    game_.tick();
  }

  EXPECT_EQ(gfmap["swapBuffers"], 5);
  EXPECT_EQ(gfmap["pollEvents"], 5);
}

TEST_F(GameTest, GameLoopDeltaTime) {
  const std::chrono::milliseconds delay(1000);

  game_.tick();
  const auto time_before = game_.dt();

  std::this_thread::sleep_for(delay);
  game_.tick();

  const auto time_after = game_.dt();
  const auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(time_after - time_before);

  ASSERT_EQ(time_diff.count(), delay.count());
}
