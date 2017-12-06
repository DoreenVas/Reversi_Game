

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "DefaultLogic.h"
#include "RemotePlayer.h"
#include <limits>
#include <cstdlib>

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

/*
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
*/

using namespace std;
int main() {
    RemotePlayer client("127.0.0.1", 8002);
    try {
        client.connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
    }
    int num1, num2;
    char op;
    int i = 0;
    while (i<3) {
        cout << "Enter an exercise (e.g., 15*19):";
        cin >> num1 >> op >> num2;
        cout << "Sending exercise: " << num1 << op
             << num2 << endl;
        try {
            int result = client.sendExercise(num1,
                                             op, num2);
            cout << "Result: " << result << endl;
        } catch (const char *msg) {
            cout << "Failed to send exercise to server. Reason: " << msg << endl;
        }
        i++;
    }
}










