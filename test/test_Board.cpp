

#include <gtest/gtest.h>
#include "../Board.h"

//checks to see if the board is initialized correctly for different sizes
TEST (test_Board,inizialize_board_4) {
    Board board(4);
    EXPECT_EQ(board.cellAt(1,1)->getContains(),'o');
    EXPECT_EQ(board.cellAt(2,2)->getContains(),'o');
    EXPECT_EQ(board.cellAt(2,1)->getContains(),'x');
    EXPECT_EQ(board.cellAt(1,2)->getContains(),'x');
    EXPECT_FALSE(board.cellAt(1,1)->isOption());
    EXPECT_FALSE(board.cellAt(2,2)->isOption());
    EXPECT_FALSE(board.cellAt(1,2)->isOption());
    EXPECT_FALSE(board.cellAt(2,1)->isOption());
}
