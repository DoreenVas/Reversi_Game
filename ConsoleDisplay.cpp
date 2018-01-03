
#include "ConsoleDisplay.h"
#include <limits>

void ConsoleDisplay::printBoard(Board *board) const {
    cout << "   ";
    for (size_t i = 0; i < board->getBoardSize(); ++i) {
        cout << i + 1 << "  ";
    }
    cout << endl;

    for (int row = 0; row < board->getBoardSize(); row++) {
        cout << row + 1 << "| ";
        for (int col = 0; col < board->getBoardSize(); col++) {
            switch (board->cellAt(row,col)->getContains()) {
                case Empty:
                    cout << " | ";
                    break;
                case White:
                    cout << "o| ";
                    break;
                case Black:
                    cout << "x| ";
                    break;
            }
        }

        cout << endl << "..";
        for (size_t i = 0; i < board->getBoardSize(); i++) {
            cout << "...";
        }
        cout <<endl;

    }
}

void ConsoleDisplay::printChosenMove(pair<int, int> chosenMove,Contains type) const {
    cout <<playerDisk(type)<< " played  " <<chosenMove.first+1<<","<<chosenMove.second+1<<  endl;

}

void ConsoleDisplay::printEnd(Contains type,int playerScore, int rivalScore) const {
    char playerDisk,rivalDisk;
    switch (type){
        case Black: {
            playerDisk = 'X';
            rivalDisk-'O';
            break;
        }
        case White: {
            playerDisk = 'O';
            rivalDisk='X';
            break;
        }
    }
    if (playerScore > rivalScore) {
        cout << "The winner is " << playerDisk << "!!  with a score of: " << playerScore;
    } else if (playerScore < rivalScore) {
        cout << "The winner is " << rivalDisk << "!!  with a score of: " << rivalScore;
    } else cout << "its a tie!";
}

void ConsoleDisplay::printMessage(const string message) const {
    cout<<message<<endl;
}

void ConsoleDisplay::noMoves(Contains type) const {
    cout << playerDisk(type)<<" also has no moves available, So the game is over"<<endl;
}

int ConsoleDisplay::getOpponentType()const {
    cout<<"Choose an opponent type:"<<endl;
    cout<<"1. a human local player"<<endl;
    cout<<"2. an AI player"<<endl;
    cout<<"3. a remote player"<<endl;
    bool validInput=false;
    int opponentType;
    while (!validInput) {
        cin >> opponentType ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "that is not an integer, try again" << endl;
        }
        else if (opponentType != 1 && opponentType !=2 && opponentType !=3)
            cout << "valid input is 1-3, try again" << endl;
        else {
            validInput = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        }
    }
    return opponentType;
}


void ConsoleDisplay::printPossibleMoves( vector<pair<int, int> > movesVec)const {
    for (int i=0;i<movesVec.size();i++){
        cout<< "(" <<movesVec[i].first+1<< "," <<movesVec[i].second+1<< ") ";
    }
}

void ConsoleDisplay::yourMove(Contains type) const {
    cout <<playerDisk(type)<< ": It's your move" << endl;
    cout << "Your possible moves are: ";
}

void ConsoleDisplay::enterMove() const {
    cout << endl << "Please enter your move, write row than space than col: " << endl;
}

char ConsoleDisplay::playerDisk(Contains type) const {
    char playerDisk;
    switch (type){
        case Black: {
            playerDisk = 'X';
            break;
        }
        case White: {
            playerDisk = 'O';
            break;
        }
    }
    return playerDisk;
}

int ConsoleDisplay::getCommand() const {
    cout<<"Choose your game option:"<<endl;
    cout<<"1. start a new game"<<endl;
    cout<<"2. join an existing game"<<endl;
    cout<<"3. see list of available games"<<endl;
    bool validInput=false;
    int opponentType;
    while (!validInput) {
        cin >> opponentType ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "that is not an integer, try again" << endl;
        }
        else if (opponentType != 1 && opponentType !=2 && opponentType !=3)
            cout << "valid input is 1-3, try again" << endl;
        else {
            validInput = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        }
    }
    return opponentType;
}

string ConsoleDisplay::chooseName() const {
    cout<<"choose a name for the game"<<endl;
    string name;
    cin >> name;
    return name;
}
