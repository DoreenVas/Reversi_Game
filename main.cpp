

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "DefaultLogic.h"
#include "RemotePlayer.h"
#include <fstream>
#include <cstdlib>
#include "ConsoleDisplay.h"

using namespace std;

#define FIRST_PLAYER 1
#define LOCAL_GAME 2
#define REMOTE_GAME 3
#define FAIL -1
#define SUCCESS 0

bool commandLoop(ClientServerCommunication *client,Display *displayP);

// makes the objects and runs the game
int main(){
    Board board(4);
    Board *boardP=&board;
    Player *player1P;
    Player *player2P;
    ConsoleDisplay display=ConsoleDisplay();
    Display *displayP=&display;
    int opponentType=display.getOpponentType();
    switch (opponentType){
        case 1:
            player1P=new HumanPlayer(displayP,Black,LOCAL_GAME);
            player2P =new HumanPlayer(displayP,White,LOCAL_GAME);
            break;
        case 2:
            player1P=new HumanPlayer(displayP,Black,LOCAL_GAME);
            player2P =new AIPlayer(displayP,White);
            break;
        case 3:
            //read ip and port from file
            int port;
            string ip;
            ifstream settingFile;
            settingFile.open("../client_settings.txt");
            if(!settingFile.is_open()){
                displayP->printMessage("failed to open file");
                return 0;
            }
            settingFile>>ip;
            settingFile>>port;
            settingFile.close();
            const char* ip2=ip.c_str();

            ClientServerCommunication client(ip2, port);

            if(commandLoop(&client,displayP)==false){
                return 0;
            }

            int clientTurn;
            try {
                clientTurn = client.getClientTurn();
            }catch (const char *msg){
                displayP->printMessage("Fail. Reason:");
                displayP->printMessage(msg);
                return 0;
            }
            if(clientTurn==FIRST_PLAYER){
                player1P=new HumanPlayer(displayP,Black,REMOTE_GAME,client);
                player2P =new RemotePlayer(displayP,White,client);
            }else{
                player1P =new RemotePlayer(displayP,Black,client);
                player2P=new HumanPlayer(displayP,White,REMOTE_GAME,client);
            }
            break;
    }

    DefaultLogic logic= DefaultLogic(player1P,player2P);
    GameLogic *logicP= &logic;
    Game game(player1P,player2P,boardP,logicP,displayP);
    game.play();
}

bool commandLoop(ClientServerCommunication *client,Display *displayP) {
    int status = FAIL;
    while (status == FAIL) {
        try {
            client->connectToServer(displayP);
        } catch (const char *msg) {
            displayP->printMessage("Failed to connect to server. Reason:");
            displayP->printMessage(msg);
            return false;
        }
        int command = displayP->getCommand();
        string name,name2,name3,msg;
        switch (command) {

            case 1://start
                name = displayP->chooseName();
                try {
                    msg="start ";
                    msg.append(name);
                    client->sendCommandToServer(msg);
                    int status2 = client->getStatusFromServer();
                    if (status2 == SUCCESS) {
                        status = SUCCESS;
                        displayP->printMessage("waiting for other player to join");
                    } else if (status2 == FAIL) {
                        displayP->printMessage("a game with that name already exists");
                    }
                } catch (const char *msg) {
                    displayP->printMessage("Failed . Reason:");
                    displayP->printMessage(msg);
                    return false;
                }
                break;
            case 2://join
                name2 = displayP->chooseName();
                try {
                    msg="join ";
                    msg.append(name2);
                    client->sendCommandToServer(msg);
                    int status3 = client->getStatusFromServer();
                    if (status3 == SUCCESS) {
                        status = SUCCESS;
                    } else if (status3 == FAIL) {
                        displayP->printMessage("no game with that name is available");
                    }
                } catch (const char *msg) {
                    displayP->printMessage("Failed . Reason:");
                    displayP->printMessage(msg);
                    return false;
                }
                break;
            case 3://list_games
                try {
                    msg="list_games ";
                    client->sendCommandToServer(msg);
                    displayP->printMessage("list of available games:");
                    int size = client->getStatusFromServer();
                    if (size == 0) {
                        displayP->printMessage("there are no games available ");
                    } else {
                        for (int i = 0; i < size; i++) {
                            name3 = client->getNameFromServer();
                            displayP->printMessage(name3);
                        }
                    }

                } catch (const char *msg) {
                    displayP->printMessage("Failed . Reason:");
                    displayP->printMessage(msg);
                    return false;
                }
                break;
        }
    }
    return true;
}

