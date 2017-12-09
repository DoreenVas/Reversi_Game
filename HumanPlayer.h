

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
* the input: Contains x, int gameType
* the output: none
* the function operation:initializes by using the base Player constructor,and the given values,
 * also initializes the connector to a default non used server for compilation
***************************************************************************************************/
    HumanPlayer(Contains x, int gameType);
/***************************************************************************************************
* constructor name:HumanPlayer
* the input: Contains x,int gameType,ClientServerCommunication connector
* the output: none
* the function operation:initializes by using the base Player constructor and the values received
***************************************************************************************************/
    HumanPlayer(Contains x, int gameType,ClientServerCommunication connector);
/***************************************************************************************************
* constructor name:HumanPlayer
* the input: other player
* the output: none
* the function operation:it is a copy constructor initialized by the base Player copy constructor
 * also initializes the connector to a default non used server for compilation
***************************************************************************************************/
    HumanPlayer(const Player &other);
    //all has description in Player class
    void preMovePrint(Board *board);
    int postMovePrint();
/***************************************************************************************
* function name: chooseMove
* the input: Board* board,GameLogic* logic
* the output: the chosen move pair
* the function operation: receives the move from the player by the console
****************************************************************************************/
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
