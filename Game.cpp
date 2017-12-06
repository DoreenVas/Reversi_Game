

#include "Game.h"
#include <iostream>
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
        if (player->isNoMoves()  && !rival->isNoMoves()) {
            cout << "No moves available, hence your turn is passed "<<endl;
        }
        else if (player->isNoMoves() && rival->isNoMoves() ) {
            cout << "You also have no moves available, So the game is over"<<endl;
            printEnd();
            break;
        }
        else {
            int *arrP=player->chooseMove(board,logic);
            logic->makeMove(*arrP, *(arrP+1),board);
            logic->resetPossibleMoves(board);
            player->postMovePrint();
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


