

#ifndef HW1_HUMANPLAYER_H
#define HW1_HUMANPLAYER_H
#include "Player.h"
#include "ClientServerCommunication.h"

#define LOCAL_GAME 2
#define REMOTE_GAME 3

class HumanPlayer: public Player {
public:
/***************************************************************************************************
* constructor name:HumanPlayer
* the input: char x
* the output: none
* the function operation:initializes by using the base Player constructor
***************************************************************************************************/
    HumanPlayer(char x, int gameType);

    HumanPlayer(char x, int gameType,ClientServerCommunication connector);
/***************************************************************************************************
* constructor name:HumanPlayer
* the input: other player
* the output: none
* the function operation:it is a copy constructor initialized by the base Player copy constructor
***************************************************************************************************/
    HumanPlayer(const Player &other);
    //all has description in Player class
    void preMovePrint(Board *board);
    int postMovePrint();
    pair<int,int> chooseMove(Board* board,GameLogic* logic);
    int gameType;

private:
/***************************************************************************************
* function name: printPossibleMoves
* the input: none
* the output: none
* the function operation:goes throw the vector of moves and prints each move
****************************************************************************************/
    void printPossibleMoves();
    ClientServerCommunication connector;
};


#endif //HW1_HUMANPLAYER_H
