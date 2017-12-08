

#include "Game.h"
#include "HumanPlayer.h"
#include "RemotePlayer.h"
#include <iostream>
#include <limits>

using namespace std;


Game::Game(Player *player1P,Player *player2P,Board *boardP, GameLogic *logicP) {
    gameOn=true;
    player=player1P;//player is the player currently playing
    rival=player2P;
    board=boardP;
    logic=logicP;
}


void Game::play() {
    while (gameOn) {
        cout << "Current board:" << endl << endl;
        board->printBoard();
        logic->possibleMoves(board);
        player->preMovePrint(board);
        if (player->isNoMoves()  && !rival->isNoMoves() && dynamic_cast<RemotePlayer*>(player)==NULL) {
            cout << "No moves available, hence your turn is passed "<<endl;
            cout << "Enter any key to continue." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(dynamic_cast<HumanPlayer*>(player)!=NULL && dynamic_cast<HumanPlayer*>(player)->gameType==REMOTE_GAME){
                player->chosenMove.first=NO_MOVE;
                player->postMovePrint();
            }
        }
        else if (player->isNoMoves() && rival->isNoMoves() ) {
            cout << player->getDisk()<<" also has no moves available, So the game is over"<<endl;
            printEnd();
            break;
        }
        else {
            pair<int,int> chosenMove=player->chooseMove(board,logic);
            if (chosenMove.first==PROBLEM)
                return;
            else if (chosenMove.first!=NO_MOVE) {
                logic->makeMove(chosenMove.first, chosenMove.second, board);
                logic->resetPossibleMoves(board);
                int check = player->postMovePrint();
                if (check == PROBLEM)
                    return;
            }
        }
        if (player->getScore() + rival->getScore() == board->getBoardSize()*board->getBoardSize()) {
            cout << "Final board:" << endl << endl;
            board->printBoard();
            printEnd();
            break;
        }
        swap(player,rival);
        logic->switchPlayer();

    }
}

void Game:: swap(Player *&player, Player *&rival)//we want the pointers we sent to change so we send them as a reference
{
    Player *pSwap = player;
    player = rival;
    rival = pSwap;
}

void Game::printEnd() const {
    if (player->getScore() > rival->getScore()) {
        cout << "The winner is " << player->getDisk() << "!!  with a score of: " << player->getScore();
    } else if (player->getScore() < rival->getScore()) {
        cout << "The winner is " << rival->getDisk() << "!!  with a score of: " << rival->getScore();
    } else cout << "its a tie!";
}


