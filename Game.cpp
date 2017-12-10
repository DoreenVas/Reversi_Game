

#include "Game.h"
#include "HumanPlayer.h"
#include "RemotePlayer.h"
#include <limits>

using namespace std;


Game::Game(Player *player1P,Player *player2P,Board *boardP, GameLogic *logicP ,Display *display) {
    gameOn=true;
    player=player1P;//player is the player currently playing
    rival=player2P;
    board=boardP;
    logic=logicP;
    this->display=display;
}


void Game::play() {
    while (gameOn) {
        display->printMessage("Current board:");
        display->printBoard(board);
        logic->possibleMoves(board);
        player->preMovePrint(board);
        if (player->isNoMoves()  && !rival->isNoMoves() && dynamic_cast<RemotePlayer*>(player)==NULL) {
            display->printMessage("No moves available, hence your turn is passed ");
            display->printMessage("Enter any key to continue.");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(dynamic_cast<HumanPlayer*>(player)!=NULL && dynamic_cast<HumanPlayer*>(player)->gameType==REMOTE_GAME){
                player->chosenMove.first=NO_MOVE;
                player->postMovePrint(board);
            }
        }
        else if (player->isNoMoves() && rival->isNoMoves() ) {
            display->noMoves(player->getType());
            display->printEnd(player->getType(),player->getScore(),rival->getScore());
            break;
        }
        else {
            pair<int,int> chosenMove=player->chooseMove(board,logic);
            if (chosenMove.first==PROBLEM)
                return;
            else if (chosenMove.first!=NO_MOVE) {
                logic->makeMove(chosenMove.first, chosenMove.second, board);
                logic->resetPossibleMoves(board);
                int check = player->postMovePrint(board);
                if (check == PROBLEM)
                    return;
            }
        }
        if (player->getScore() + rival->getScore() == board->getBoardSize()*board->getBoardSize()) {
            display->printMessage("Final board:");
            display->printBoard(board);
            display->printEnd(player->getType(),player->getScore(),rival->getScore());
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




