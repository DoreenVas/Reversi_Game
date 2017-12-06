

#ifndef HW1_AIPLAYER_H
#define HW1_AIPLAYER_H

#include "Player.h"

class AIPlayer: public Player {

public:
/***************************************************************************************************
* constructor name:AIPlayer
* the input: char x
* the output: none
* the function operation:initializes by using the base Player constructor
***************************************************************************************************/
    explicit AIPlayer(char x);
/***************************************************************************************************
* constructor name:AIPlayer
* the input: other player
* the output: none
* the function operation:it is a copy constructor initialized by the base Player copy constructor
***************************************************************************************************/
    AIPlayer(const Player &other);
    //all has description in Player class
    void preMovePrint(Board *board);
    void postMovePrint();
    int* chooseMove(Board* board,GameLogic* logic);

private:
    int arr[2];
};


#endif //HW1_AIPLAYER_H
