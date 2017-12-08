
#ifndef REVERSI_ONLINEPLAYER_H
#define REVERSI_ONLINEPLAYER_H

#include "Player.h"
#include "ClientServerCommunication.h"

class RemotePlayer : public Player {

public:
    RemotePlayer(char x, ClientServerCommunication connector);
    void preMovePrint(Board *board);
    pair<int,int> chooseMove(Board* board,GameLogic* logic);
    int postMovePrint();

private:
    ClientServerCommunication connector;
};



#endif //REVERSI_ONLINEPLAYER_H