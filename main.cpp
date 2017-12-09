

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "DefaultLogic.h"
#include "RemotePlayer.h"
#include <limits>
#include <fstream>

using namespace std;

#define FIRST_PLAYER 1
#define LOCAL_GAME 2
#define REMOTE_GAME 3

int getOpponentType(){
    cout<<"Choose an opponent type:"<<endl;
    cout<<"1. a human local player"<<endl;
    cout<<"2. an AI player"<<endl;
    cout<<"3. a remote player"<<endl;
    bool validInput=false;
    int opponentType;
    while (!validInput) {
        cin >> opponentType ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "that is not an integer, try again" << endl;
        }
        else if (opponentType != 1 && opponentType !=2 && opponentType !=3)
            cout << "valid input is 1-3, try again" << endl;
        else {
            validInput = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        }
    }
    return opponentType;
}

// makes the objects and runs the game
int main(){
    Board board(4);
    Board *boardP=&board;
    Player *player1P;
    Player *player2P;
    int opponentType=getOpponentType();
    switch (opponentType){
        case 1:
            player1P=new HumanPlayer(Black,LOCAL_GAME);
            player2P =new HumanPlayer(White,LOCAL_GAME);
            break;
        case 2:
            player1P=new HumanPlayer(Black,LOCAL_GAME);
            player2P =new AIPlayer(White);
            break;
        case 3:
            //read ip and port from file
            int port;
            string ip;
            ifstream settingFile;
            settingFile.open("../client_settings.txt");
            if(!settingFile.is_open()){
                cout<<"failed to open file";
                return 0;
            }
            settingFile>>ip;
            settingFile>>port;
            settingFile.close();
            const char* ip2=ip.c_str();

            ClientServerCommunication client(ip2, port);
            try{
               client.connectToServer();
            }catch (const char *msg){
                cout<<"Failed to connect to server. Reason:"<<msg<<endl;
                return 0;
            }
            int clientTurn=client.getClientTurn();
            if(clientTurn==FIRST_PLAYER){
                player1P=new HumanPlayer(Black,REMOTE_GAME,client);
                player2P =new RemotePlayer(White,client);
            }else{
                player1P =new RemotePlayer(Black,client);
                player2P=new HumanPlayer(White,REMOTE_GAME,client);
            }
    }

    DefaultLogic logic= DefaultLogic(player1P,player2P);
    GameLogic *logicP= &logic;
    Game game(player1P,player2P,boardP,logicP);
    game.play();
}
