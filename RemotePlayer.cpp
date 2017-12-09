
#include <iostream>
#include "RemotePlayer.h"


RemotePlayer::RemotePlayer(Contains x, ClientServerCommunication connector):Player(x),connector(connector) {
}

void RemotePlayer::preMovePrint(Board *board) {

}

pair<int,int> RemotePlayer::chooseMove(Board *board, GameLogic *logic) {
    cout<<"Waiting for other player's move..."<<endl;
    try{
        chosenMove=connector.getMoveFromServer();
    }catch (const char *msg){
        cout<<msg<<endl;
        return make_pair(PROBLEM,PROBLEM);
    }
    if(chosenMove.first==NO_MOVE)
        cout<<"He had no possible moves, so it's your turn"<<endl;
    return chosenMove;
}

int RemotePlayer::postMovePrint() {
    cout <<type<< " played  " <<chosenMove.first+1<<","<<chosenMove.second+1<<  endl;
    return 0;
}

