#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../Board.h"
#include "../DefaultLogic.h"
#include "../HumanPlayer.h"

/*
we make the next board and check for possible moves
its player 'x' turn and we especially want to check that the bound at 3,1 is recognized
  1  2  3  4  5  6  7  8
1| |  |  |  |  |  |  |  |
..........................
2| | o|  |  |  |  |  |  |
..........................
3|o| o| o| x|  |  |  |  |
..........................
4| |  | x| x| x|  |  |  |
..........................
5| |  |  | x| o|  |  |  |
..........................
6| |  |  |  |  |  |  |  |
..........................
7| |  |  |  |  |  |  |  |
..........................
8| |  |  |  |  |  |  |  |
..........................
 */
TEST (test_DefaultLogic,possible_moves_check) {
    Board board(8);
    HumanPlayer *player=new HumanPlayer(Black,LOCAL_GAME);
    HumanPlayer *rival=new HumanPlayer(White,LOCAL_GAME);
    DefaultLogic logic=DefaultLogic(player,rival);
    player->setScore(5);
    rival->setScore(5);
    board.cellAt(2,0)->setContains(White);
    board.cellAt(1,1)->setContains(White);
    board.cellAt(2,1)->setContains(White);
    board.cellAt(2,2)->setContains(White);
    board.cellAt(4,4)->setContains(White);
    board.cellAt(2,3)->setContains(Black);
    board.cellAt(3,2)->setContains(Black);
    board.cellAt(3,3)->setContains(Black);
    board.cellAt(4,3)->setContains(Black);
    board.cellAt(3,4)->setContains(Black);
    logic.possibleMoves(&board);
    vector< pair<int,int> > correctMoves;
    //inserting the correct moves
    correctMoves.push_back(make_pair(0,0));
    correctMoves.push_back(make_pair(1,0));
    correctMoves.push_back(make_pair(1,2));
    correctMoves.push_back(make_pair(4,5));
    correctMoves.push_back(make_pair(5,4));
    correctMoves.push_back(make_pair(5,5));
    vector< pair<int,int> > logicMoves;
    //getting the moves that Class DefaultLogic calculated
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if (board.cellAt(i,j)->isOption())
                logicMoves.push_back(make_pair(i,j));
        }
    }
    EXPECT_THAT(logicMoves,correctMoves );
}

/*
we make the next board and check for possible moves
its player 'x' turn and we expect to see no moves possible
  1  2  3  4
1|o| o| o|  |
..............
2|o| o| x|  |
..............
3|o| x| x| x|
..............
4| |  |  |  |
 */
TEST (test_DefaultLogic,no_moves_check) {
    Board board(4);
    HumanPlayer *player=new HumanPlayer(Black,LOCAL_GAME);
    HumanPlayer *rival=new HumanPlayer(White,LOCAL_GAME);
    DefaultLogic logic=DefaultLogic(player,rival);
    player->setScore(4);
    rival->setScore(6);
    board.cellAt(0,0)->setContains(White);
    board.cellAt(0,1)->setContains(White);
    board.cellAt(0,2)->setContains(White);
    board.cellAt(1,0)->setContains(White);
    board.cellAt(1,1)->setContains(White);
    board.cellAt(2,0)->setContains(White);
    board.cellAt(1,2)->setContains(Black);
    board.cellAt(2,1)->setContains(Black);
    board.cellAt(2,2)->setContains(Black);
    board.cellAt(2,3)->setContains(Black);
    logic.possibleMoves(&board);
    vector< pair<int,int> > logicMoves;
    //getting the moves the Class DefaultLogic calculated
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (board.cellAt(i,j)->isOption())
                logicMoves.push_back(make_pair(i,j));
        }
    }
    EXPECT_TRUE(logicMoves.empty());
}


/*
 we make the next board and check if the possible moves updates the flip options and their sum correctly
 its 'o' turn
  1  2  3  4
1|o| x|  |  |
..............
2|x| x| x|  |
..............
3| | x| o|  |
..............
4| |  |  |  |
..............
 */
TEST (test_DefaultLogic,flip_options_check) {
    Board board(4);
    HumanPlayer *rival=new HumanPlayer(Black,LOCAL_GAME);
    HumanPlayer *player=new HumanPlayer(White,LOCAL_GAME);
    DefaultLogic logic=DefaultLogic(player,rival);
    player->setScore(2);
    rival->setScore(5);
    board.cellAt(0,0)->setContains(White);
    board.cellAt(2,2)->setContains(White);
    board.cellAt(0,1)->setContains(Black);
    board.cellAt(1,0)->setContains(Black);
    board.cellAt(1,1)->setContains(Black);
    board.cellAt(1,2)->setContains(Black);
    board.cellAt(2,1)->setContains(Black);
    logic.possibleMoves(&board);
    EXPECT_EQ(board.cellAt(0,2)->getFlipSum(),2);//total flips of 'x' disks possible need to be 2
    EXPECT_EQ(board.cellAt(2,0)->getFlipSum(),2);
    int correctFlipOptions[3][3];
    for (int i=0;i<3;i++) {
        for (int j = 0; j < 3; j++)
            correctFlipOptions[i][j] = 0;
    }
    correctFlipOptions[1][0]=1;
    correctFlipOptions[2][1]=1;
    for (int i=0;i<3;i++)
        for (int j = 0; j < 3; j++)
            EXPECT_EQ(board.cellAt(0,2)->getFlipOptions(i,j),correctFlipOptions[i][j]);
}

/*
check make move correctness and players score correct update
 we test the original board of size 4:
  1  2  3  4
1| |  |  |  |
..............
2| | o| x|  |
..............
3| | x| o|  |
..............
4| |  |  |  |
..............
*/
TEST (test_DefaultLogic,make_move_check) {
    Board board(4);
    HumanPlayer *player=new HumanPlayer(Black,LOCAL_GAME);
    HumanPlayer *rival=new HumanPlayer(White,LOCAL_GAME);
    DefaultLogic logic=DefaultLogic(player,rival);
    logic.possibleMoves(&board);
    logic.makeMove(0,1,&board);
    EXPECT_EQ(player->getScore(),4);
    EXPECT_EQ(rival->getScore(),1);

    //now we compare the board disks
    char correctBoardTable[4][4];
    for (int i=0;i<3;i++) {
        for (int j = 0; j < 3; j++)
            correctBoardTable[i][j] = Empty;
    }
    correctBoardTable[0][1] = Black;
    correctBoardTable[1][1] = Black;
    correctBoardTable[1][2] = Black;
    correctBoardTable[2][1] = Black;
    correctBoardTable[2][2] = White;

    for (int i=0;i<3;i++)
        for (int j = 0; j < 3; j++)
            EXPECT_EQ(correctBoardTable[i][j],board.cellAt(i,j)->getContains());

}
