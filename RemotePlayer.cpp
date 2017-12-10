
#include <iostream>
#include "RemotePlayer.h"


RemotePlayer::RemotePlayer(Display *display,Contains x, ClientServerCommunication connector):Player(display,x)
        ,connector(connector) {
}

void RemotePlayer::preMovePrint(Board *board) {

}

pair<int,int> RemotePlayer::chooseMove(Board *board, GameLogic *logic) {
    display->printMessage("Waiting for other player's move...");
    try{
        chosenMove=connector.getMoveFromServer();
    }catch (const char *msg){
        display->printMessage(msg);
        return make_pair(PROBLEM,PROBLEM);
    }
    if(chosenMove.first==NO_MOVE)
        display->printMessage("He had no possible moves, so it's your turn");
    return chosenMove;
}

int RemotePlayer::postMovePrint(Board *board) {
    display->printChosenMove(chosenMove,type);
}

