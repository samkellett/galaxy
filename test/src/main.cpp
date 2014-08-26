#include "gtest/gtest.h"
#include "gmock/gmock.h"

#define GXY_MOCK_OPENGL
#include <gxy/gfx.h>

int main(int argc, char **argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

