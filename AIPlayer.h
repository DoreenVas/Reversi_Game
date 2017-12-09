

#ifndef HW1_AIPLAYER_H
#define HW1_AIPLAYER_H

#include "Player.h"

class AIPlayer: public Player {

public:
/***************************************************************************************************
* constructor name:AIPlayer
* the input: Contains x
* the output: none
* the function operation:initializes by using the base Player constructor
***************************************************************************************************/
    explicit AIPlayer(Contains x);
/***************************************************************************************************
* constructor name:AIPlayer
* the input: other player
* the output: none
* the function operation:it is a copy constructor initialized by the base Player copy constructor
***************************************************************************************************/
    AIPlayer(const Player &other);
    //all has description in Player class
    void preMovePrint(Board *board);
    int postMovePrint();
/***************************************************************************************
* function name: chooseMove
* the input: Board* board,GameLogic* logic
* the output: the chosen move pair
* the function operation: calculates the best move by the minMax algorithm
****************************************************************************************/
    pair<int,int> chooseMove(Board* board,GameLogic* logic);

};


#endif //HW1_AIPLAYER_H
