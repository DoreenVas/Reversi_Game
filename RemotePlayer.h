
#ifndef REVERSI_ONLINEPLAYER_H
#define REVERSI_ONLINEPLAYER_H

#include "Player.h"
#include "ClientServerCommunication.h"

/*****************************************************************************************************
* class name: RemotePlayer
* description: the remote player representation
******************************************************************************************************/
class RemotePlayer : public Player {

public:
/***************************************************************************************************
* constructor name:RemotePlayer
* the input: Contains x, ClientServerCommunication connector
* the output: none
* the function operation:initializes by using the base Player constructor,and the given value connector                             *
***************************************************************************************************/
    RemotePlayer(Contains x, ClientServerCommunication connector);
    void preMovePrint(Board *board);
/***************************************************************************************
* function name: chooseMove
* the input: Board* board,GameLogic* logic
* the output: the chosen move pair
* the function operation: reads the move from the server
****************************************************************************************/
    pair<int,int> chooseMove(Board* board,GameLogic* logic);
    int postMovePrint();

private:
    ClientServerCommunication connector;
};



#endif //REVERSI_ONLINEPLAYER_H