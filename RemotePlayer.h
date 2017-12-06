
#ifndef REVERSI_ONLINEPLAYER_H
#define REVERSI_ONLINEPLAYER_H


class RemotePlayer {
public:
    RemotePlayer(const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1, char op, int arg2);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};



#endif //REVERSI_ONLINEPLAYER_H