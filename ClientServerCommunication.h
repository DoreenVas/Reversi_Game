
#ifndef HW1_CLIENTSERVERCOMMUNICATION_H
#define HW1_CLIENTSERVERCOMMUNICATION_H

#include <utility>
using namespace std;

class ClientServerCommunication {
public:
    ClientServerCommunication(const char *serverIP, int serverPort);
    void connectToServer();
    int getClientTurn();
    void sendMoveToServer(pair<int,int> chosenMove);
    pair <int,int> getMoveFromServer();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;


};

#endif //HW1_CLIENTSERVERCOMMUNICATION_H
