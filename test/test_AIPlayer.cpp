#include "gtest/gtest.h"
#include "../Board.h"
#include "../AIPlayer.h"
#include "../HumanPlayer.h"
#include "../DefaultLogic.h"

//test for AIPlayer to see if he chooses the right move
TEST (test_AIPlayer,simple_choose){
    Board board(8);
    AIPlayer *comp=new AIPlayer('o');
    HumanPlayer *human=new HumanPlayer('x');
    DefaultLogic logic=DefaultLogic(comp,human);//comp is currently playing
    human->setScore(4);
    comp->setScore(1);
    board.cellAt(2,3)->setContains('x');// actual cell on board 3,4
    board.cellAt(3,3)->setContains('x');// actual cell on board 4,4
    logic.possibleMoves(&board);
    int *arrP=comp->chooseMove(&board,&logic);
    EXPECT_EQ(*arrP,2);
    EXPECT_EQ(*(arrP+1),2);//actual cell on board 3,3

}

//testing if AIPlayer will choose the move which makes the rival with no moves like it should
TEST (test_AIPlayer,no_moves_for_rival) {
    Board board(4);
    AIPlayer *comp=new AIPlayer('o');
    HumanPlayer *human=new HumanPlayer('x');
    DefaultLogic logic=DefaultLogic(comp,human);//comp is currently playing
    human->setScore(6);
    comp->setScore(3);
//notice that in the actual board each row,col is actually the writen number +1
    board.cellAt(0,0)->setContains('o');// example- on the board its in place (1,1)
    board.cellAt(0,1)->setContains('o');
    board.cellAt(0,2)->setContains('o');
    board.cellAt(1,0)->setContains('x');
    board.cellAt(1,1)->setContains('x');
    board.cellAt(1,2)->setContains('x');
    board.cellAt(2,1)->setContains('x');
    board.cellAt(2,2)->setContains('x');
    board.cellAt(2,3)->setContains('x');
    logic.possibleMoves(&board);
    int *arrP=comp->chooseMove(&board,&logic);
    EXPECT_EQ(*arrP,2);
    EXPECT_EQ(*(arrP+1),0);
}

