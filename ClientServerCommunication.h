
#ifndef HW1_CLIENTSERVERCOMMUNICATION_H
#define HW1_CLIENTSERVERCOMMUNICATION_H

#include <utility>
#include "Display.h"

using namespace std;

/*****************************************************************************************************
* class name: ClientServerCommunication
* description: contains the communication functions between the clients and the server
******************************************************************************************************/
class ClientServerCommunication {
public:
/***************************************************************************************************
* constructor name:ClientServerCommunication
* the input: an ip and port
* the output: none
* the function operation:initializes the private variables to the ones we got and clientSocket to 0
***************************************************************************************************/
    ClientServerCommunication(const char *serverIP, int serverPort);
/***************************************************************************************
* function name: connectToServer
* the input: none
* the output: none
* the function operation:connecting client to the server
****************************************************************************************/
    void connectToServer(Display *displayP);
/***************************************************************************************
* function name: getClientTurn
* the input: none
* the output: int equals 1 or 2 (first or second)
* the function operation:when the connection is established the server sends the players turn, the function reads it
****************************************************************************************/
    int getClientTurn();
/***************************************************************************************
* function name: sendMoveToServer
* the input: pair<int,int> chosenMove
* the output: none
* the function operation: sends the move to the server int by int, throws exception if something went wrong
****************************************************************************************/
    void sendMoveToServer(pair<int,int> chosenMove);
/***************************************************************************************
* function name: getMoveFromServer
* the input: none
* the output: pair<int,int> (the chosenMove)
* the function operation:reads the move from the server int by int, throws exception if something went wrong
****************************************************************************************/
    pair <int,int> getMoveFromServer();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;

};

#endif //HW1_CLIENTSERVERCOMMUNICATION_H
