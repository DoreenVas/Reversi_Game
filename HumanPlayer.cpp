
#include <iostream>
#include "HumanPlayer.h"
#include <limits>
using namespace std;

HumanPlayer::HumanPlayer(char x):Player::Player(x){}//calls the Class 'Player' constructor

HumanPlayer::HumanPlayer(const Player &other):Player::Player(other){}

void HumanPlayer::preMovePrint(Board *board) {
    cout <<disk<< ": It's your move" << endl;
    cout << "Your possible moves are: ";
    possibleMovesVector(board);
    printPossibleMoves();
}

int *HumanPlayer::chooseMove(Board* board,GameLogic* logic) {
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
    int arr[2]={a-1,b-1};
    int *arrP;
    arrP=arr;
    return arrP;
}


void HumanPlayer::printPossibleMoves() {
    for (int i=0;i<movesVec.size();i++){
        cout<< "(" <<movesVec[i].first+1<< "," <<movesVec[i].second+1<< ") ";
    }
}

void HumanPlayer::postMovePrint() {

}

