#include "gtest/gtest.h"

#include "test/rook_tests.h"
#include "test/queen_tests.h"
#include "test/king_tests.h"
#include "test/pawn_tests.h"
#include "test/knight_tests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
