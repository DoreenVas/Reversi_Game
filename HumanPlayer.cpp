
#include <iostream>
#include "HumanPlayer.h"
#include <limits>
#include <cstdlib>

using namespace std;

HumanPlayer::HumanPlayer(Contains x,int gameType):Player(x),gameType(gameType),connector("0",0){}//calls the Class 'Player' constructor

HumanPlayer::HumanPlayer(Contains x, int gameType, ClientServerCommunication connector):Player(x)
        ,gameType(gameType),connector(connector) {}

HumanPlayer::HumanPlayer(const Player &other):Player(other),connector("0",0){}


void HumanPlayer::preMovePrint(Board *board) {
    cout <<type<< ": It's your move" << endl;
    cout << "Your possible moves are: ";
    possibleMovesVector(board);
    printPossibleMoves();
}

pair<int,int> HumanPlayer::chooseMove(Board* board,GameLogic* logic) {
    int a,b;
    bool validInput=false;
    cout << endl << "Please enter your move, write row than space than col: " << endl;
    while (!validInput) {
        cin >> a >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "that is not an integer, try again" << endl;
        } else if (a > board->getBoardSize() || a < 1 || b > board->getBoardSize() || b < 1) {
            cout << "incorrect choice" << endl;
        } else if (!board->cellAt(a - 1, b - 1)->isOption()) {
            cout << "that cell is not a possible move, try again" << endl;
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


void HumanPlayer::printPossibleMoves() {
    for (int i=0;i<movesVec.size();i++){
        cout<< "(" <<movesVec[i].first+1<< "," <<movesVec[i].second+1<< ") ";
    }
}

int HumanPlayer::postMovePrint() {
    if (gameType==REMOTE_GAME){
        try{
            connector.sendMoveToServer(chosenMove);
        }catch (const char *msg){
            cout<<msg<<endl;
            return PROBLEM;
        }
    }
}