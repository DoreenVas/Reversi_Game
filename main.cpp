

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "DefaultLogic.h"
#include <limits>
using namespace std;

Player * getSecondPlayer(){
    cout<<"Choose an opponent type:"<<endl;
    cout<<"1. a human local player"<<endl;
    cout<<"2. an AI player"<<endl;
    cout<<"3. a remote player"<<endl;
    bool validInput=false;
    int secondPlayer;
    while (!validInput) {
        cin >> secondPlayer ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "that is not an integer, try again" << endl;
        }
        else if (secondPlayer != 1 && secondPlayer !=2 && secondPlayer !=3)
            cout << "valid input is 1-3, try again" << endl;
        else validInput = true;
    }
    if (secondPlayer==1){
       Player *player2 =new HumanPlayer('o');
        return player2;
    }
    else {
        Player *player2 =new  AIPlayer('o');
        return player2;
    }
}


// makes the objects and runs the game
int main(){
    Board board(8);
    Board *boardP=&board;
    HumanPlayer *player1=new HumanPlayer('x');
    Player *player1P=player1;
    Player *player2P=getSecondPlayer();
    DefaultLogic logic= DefaultLogic(player1P,player2P);
    GameLogic *logicP= &logic;
    Game game(player1P,player2P,boardP,logicP);
    game.play();

}












