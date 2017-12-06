

#ifndef HW1_HUMANPLAYER_H
#define HW1_HUMANPLAYER_H
#include "Player.h"

class HumanPlayer: public Player {
public:
/***************************************************************************************************
* constructor name:HumanPlayer
* the input: char x
* the output: none
* the function operation:initializes by using the base Player constructor
***************************************************************************************************/
    explicit HumanPlayer(char x);
/***************************************************************************************************
* constructor name:HumanPlayer
* the input: other player
* the output: none
* the function operation:it is a copy constructor initialized by the base Player copy constructor
***************************************************************************************************/
    HumanPlayer(const Player &other);
    //all has description in Player class
    void preMovePrint(Board *board);
    void postMovePrint();
    int* chooseMove(Board* board,GameLogic* logic);

private:
/***************************************************************************************
* function name: printPossibleMoves
* the input: none
* the output: none
* the function operation:goes throw the vector of moves and prints each move
****************************************************************************************/
    void printPossibleMoves();

};


#endif //HW1_HUMANPLAYER_H
