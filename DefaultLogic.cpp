
#include <iostream>
using namespace std;
#include "DefaultLogic.h"

class Player;

DefaultLogic::DefaultLogic(Player *player1P,Player  *player2P) : GameLogic( player1P, player2P){}

DefaultLogic::DefaultLogic(const GameLogic &other) : GameLogic(other){}


void DefaultLogic::possibleMoves(Board *board) {
    for (int row = 0; row < board->getBoardSize() ; row++) {
        for (int col = 0; col < board->getBoardSize(); col++) {
            if (board->cellAt(row,col)->getContains()==player->getDisk())
                checkCell(row,col,board);
        }
    }
}


void DefaultLogic::makeMove(int row, int col,Board *board) {
    board->cellAt(row,col)->setContains(player->getDisk());
    player->setScore(1);
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++){
            int sum= board->cellAt(row,col)->getFlipOptions(i,j);
            while(sum!=0){
                board->cellAt(row+sum*(i-1),col+sum*(j-1))->setContains(player->getDisk());
                player->setScore(1);
                rival->setScore(-1);
                sum--;
            }
        }
    }
}

void DefaultLogic::checkCell(int row, int col,Board *board) {
    for(int i=row-1;i<=row+1;i++){
        for(int j=col-1;j<=col+1;j++){
            if(i>=0 && i<board->getBoardSize() && j>=0 && j<board->getBoardSize() ){
                if (board->cellAt(i,j)->getContains()==rival->getDisk())
                    checkDirection(row,col,i-row,j-col,board);
            }
        }
    }
}

void DefaultLogic::checkDirection(int row,int col,int deltaRow,int deltaCol,Board *board) {
    int i = row + deltaRow;
    int j = col + deltaCol;
    int sum=0;
    while (i>=0 && i<board->getBoardSize()  && j>=0 && j<board->getBoardSize()  && board->cellAt(i,j)->getContains() == rival->getDisk()){
        i += deltaRow;
        j += deltaCol;
        sum++;
    }
    if(i>=0 && i<board->getBoardSize()  && j>=0 && j<board->getBoardSize()  && board->cellAt(i,j)->getContains()==' ') {
        board->cellAt(i,j)->setOption(true);
        board->cellAt(i,j)->changeFlipOptions(1-deltaRow,1-deltaCol,sum);// we save the sum in the direction we came from

    }
}



