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
    HumanPlayer *player=new HumanPlayer('x');
    HumanPlayer *rival=new HumanPlayer('o');
    DefaultLogic logic=DefaultLogic(player,rival);
    player->setScore(5);
    rival->setScore(5);
    board.cellAt(2,0)->setContains('o');
    board.cellAt(1,1)->setContains('o');
    board.cellAt(2,1)->setContains('o');
    board.cellAt(2,2)->setContains('o');
    board.cellAt(4,4)->setContains('o');
    board.cellAt(2,3)->setContains('x');
    board.cellAt(3,2)->setContains('x');
    board.cellAt(3,3)->setContains('x');
    board.cellAt(4,3)->setContains('x');
    board.cellAt(3,4)->setContains('x');
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
    EXPECT_THAT(logicMoves,correctMoves ) << "possible moves of player 'x' are not as they should be";
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
    HumanPlayer *player=new HumanPlayer('x');
    HumanPlayer *rival=new HumanPlayer('o');
    DefaultLogic logic=DefaultLogic(player,rival);
    player->setScore(4);
    rival->setScore(6);
    board.cellAt(0,0)->setContains('o');
    board.cellAt(0,1)->setContains('o');
    board.cellAt(0,2)->setContains('o');
    board.cellAt(1,0)->setContains('o');
    board.cellAt(1,1)->setContains('o');
    board.cellAt(2,0)->setContains('o');
    board.cellAt(1,2)->setContains('x');
    board.cellAt(2,1)->setContains('x');
    board.cellAt(2,2)->setContains('x');
    board.cellAt(2,3)->setContains('x');
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


//add check of flip options +sum
//add make move correctness and player score update

//hhh

TEST (test_DefaultLogic,flip_options_check) {
    Board board(4);
    HumanPlayer *player=new HumanPlayer('x');
    HumanPlayer *rival=new HumanPlayer('o');
    DefaultLogic logic=DefaultLogic(player,rival);
}