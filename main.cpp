

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "DefaultLogic.h"
#include "RemotePlayer.h"
#include <fstream>
#include "ConsoleDisplay.h"

using namespace std;

#define FIRST_PLAYER 1
#define LOCAL_GAME 2
#define REMOTE_GAME 3

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
            settingFile.open("client_settings.txt");
            if(!settingFile.is_open()){
                display.printMessage("failed to open file");
                return 0;
            }
            settingFile>>ip;
            settingFile>>port;
            settingFile.close();
            const char* ip2=ip.c_str();

            ClientServerCommunication client(ip2, port);
            try{
               client.connectToServer(displayP);
            }catch (const char *msg){
                display.printMessage("Failed to connect to server. Reason:");
                display.printMessage(msg);
                return 0;
            }
            int clientTurn=client.getClientTurn();
            if(clientTurn==FIRST_PLAYER){
                player1P=new HumanPlayer(displayP,Black,REMOTE_GAME,client);
                player2P =new RemotePlayer(displayP,White,client);
            }else{
                player1P =new RemotePlayer(displayP,Black,client);
                player2P=new HumanPlayer(displayP,White,REMOTE_GAME,client);
            }
    }

    DefaultLogic logic= DefaultLogic(player1P,player2P);
    GameLogic *logicP= &logic;
    Game game(player1P,player2P,boardP,logicP,displayP);
    game.play();
}

