
#include <climits>
#include <iostream>
#include "AIPlayer.h"
#include "DefaultLogic.h"


AIPlayer::AIPlayer(char x):Player::Player(x){}
AIPlayer::AIPlayer(const Player &other) : Player::Player(other) {}

void AIPlayer::preMovePrint(Board *board) {

}

pair<int,int> AIPlayer::chooseMove(Board *board,GameLogic* logic) {
    int minScoreForPlayerMove=INT_MAX;
    int rowMin=INT_MAX;
    int colMin=INT_MAX;
    possibleMovesVector(board);
    for(int i=0;i<movesVec.size();i++) {
        int maxScoreForRivalMove=INT_MIN;
        Board boardCopy(*board);
        // if (dynamic_cast<DefaultLogic*>(logic))
        // if we will have more than one inherited class we will use the above
        DefaultLogic logicCopy=DefaultLogic(*logic);
        logicCopy.makeMove(movesVec[i].first, movesVec[i].second,&boardCopy);
        logicCopy.switchPlayer();
        logicCopy.resetPossibleMoves(&boardCopy);
        logicCopy.possibleMoves(&boardCopy);
        bool noMoves=true;
        for (int row = 0; row < board->getBoardSize(); row++) {
            for (int col = 0; col < board->getBoardSize(); col++) {
                if (boardCopy.cellAt(row, col)->isOption()) {
                    noMoves=false;
                    int rivalPlayerScore=*(logicCopy.getCurrentScore());
                    int AIPlayerScore=*(logicCopy.getCurrentScore()+1);
                    int flipSum=boardCopy.cellAt(row, col)->getFlipSum(); //how many player disks the rival can flip if he plays the current cell
                    int score=(rivalPlayerScore+flipSum+1)-(AIPlayerScore-flipSum);
                    if (score>maxScoreForRivalMove) {
                        maxScoreForRivalMove = score;
                    }
                }
            }
        }
        if(noMoves==true){
            rowMin=movesVec[i].first;
            colMin=movesVec[i].second;
            break;
        }
        else if (maxScoreForRivalMove<minScoreForPlayerMove) {
            minScoreForPlayerMove = maxScoreForRivalMove;
            rowMin=movesVec[i].first;
            colMin=movesVec[i].second;
        }
    }
    chosenMove.first=rowMin;
    chosenMove.second=colMin;
    return chosenMove;
}

int AIPlayer::postMovePrint(){
    cout <<disk<< " played  " <<chosenMove.first+1<<","<<chosenMove.second+1<<  endl;
    return 0;
}


