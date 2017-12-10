
#include <iostream>
#include "HumanPlayer.h"
#include <limits>

using namespace std;

HumanPlayer::HumanPlayer(Display *display,Contains x,int gameType):Player(display,x),gameType(gameType)
        ,connector("0",0){}//calls the Class 'Player' constructor

HumanPlayer::HumanPlayer(Display *display,Contains x, int gameType, ClientServerCommunication connector)
        :Player(display,x),gameType(gameType),connector(connector) {}

HumanPlayer::HumanPlayer(const Player &other):Player(other),connector("0",0){}


void HumanPlayer::preMovePrint(Board *board) {
    display->yourMove(type);
    vector< pair<int,int> > movesVec=possibleMovesVector(board);
    display->printPossibleMoves(movesVec);
}

pair<int,int> HumanPlayer::chooseMove(Board* board,GameLogic* logic) {
    int a,b;
    bool validInput=false;
    display->enterMove();
    while (!validInput) {
        cin >> a >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            display->printMessage("that is not an integer, try again");
        } else if (a > board->getBoardSize() || a < 1 || b > board->getBoardSize() || b < 1) {
            display->printMessage("incorrect choice");
        } else if (!board->cellAt(a - 1, b - 1)->isOption()) {
            display->printMessage("that cell is not a possible move, try again");
        } else {
            validInput = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        }
    }
    chosenMove.first=a-1;
    chosenMove.second=b-1;
    return chosenMove;
}


int HumanPlayer::postMovePrint(Board *board) {
    if (gameType==REMOTE_GAME){
        try{
            connector.sendMoveToServer(chosenMove);
        }catch (const char *msg){
            display->printMessage(msg);
            return PROBLEM;
        }
    }
}