#include "gtest/gtest.h"

#include "galaxy/statemanager.h"

#include "mocks/gamestate.h"

namespace unit {

class StateManagerTest : public ::testing::Test
{
protected:
  StateManagerTest() : states_(nullptr) {}
  ~StateManagerTest()
  {
    delete states_;
  }

  galaxy::StateManager *states() const
  {
    return states_;
  }

  void SetUp()
  {
    EXPECT_TRUE(states_ == nullptr);

    states_ = new galaxy::StateManager;
    states_->push<mocks::GameStateOne>();
    states_->push<mocks::GameStateTwo>();
    states_->push<mocks::GameStateThree>();
  }

  void TearDown()
  {
    delete states_;
    states_ = nullptr;
  }

private:
  galaxy::StateManager *states_;
};

TEST_F(StateManagerTest, StatesAdded)
{
  ASSERT_FALSE(states() == nullptr);
  ASSERT_EQ(states()->size(), 3);

  EXPECT_NO_THROW({
    states()->at(0);
    states()->at(1);
    states()->at(2);
  });

  galaxy::GameState *first = states()->at(0).get();
  galaxy::GameState *last = states()->at(2).get();
  EXPECT_NE(dynamic_cast<mocks::GameStateThree *>(first), nullptr);
  EXPECT_NE(dynamic_cast<mocks::GameStateOne *>(last), nullptr);

  EXPECT_THROW(states()->at(4), std::out_of_range);
}

TEST_F(StateManagerTest, Front)
{
  std::shared_ptr<galaxy::GameState> front = states()->front();
  EXPECT_EQ(front, states()->pop_front());
  EXPECT_NE(front, states()->front());

  ASSERT_EQ(states()->size(), 2);
  
  states()->pop_front();
  states()->pop_front();
  ASSERT_EQ(states()->size(), 0);
}

TEST_F(StateManagerTest, Back)
{
  std::shared_ptr<galaxy::GameState> back = states()->back();
  EXPECT_EQ(back, states()->pop_back());
  EXPECT_NE(back, states()->back());

  ASSERT_EQ(states()->size(), 2);

  states()->pop_back();
  states()->pop_back();
  ASSERT_EQ(states()->size(), 0); 
}

} // namespace unit
