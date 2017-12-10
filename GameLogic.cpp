
#include "GameLogic.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

using namespace std;

GameLogic::GameLogic(Player *player1P,Player  *player2P) {
    player=player1P;
    rival=player2P;
}

//copy constructor
GameLogic::GameLogic(const GameLogic &other){
    if (dynamic_cast<HumanPlayer*>(other.player)) {
        Player *player2 =new HumanPlayer(*other.player);
        this->player=player2;
        Player *player3 =new AIPlayer(*other.rival);
        this->rival=player3;
    }
    else {
        Player *player2 =new AIPlayer(*other.player);
        this->player=player2;
        Player *player3 =new HumanPlayer(*other.rival);
        this->rival=player3;
    }
}
GameLogic::~GameLogic() {
    delete player;
    delete rival;
}

void GameLogic::resetPossibleMoves(Board *board) {
    for (int row = 0; row < board->getBoardSize(); row++) {
        for (int col = 0; col < board->getBoardSize(); col++) {
            board->cellAt(row,col)->setOption(false);
            board->cellAt(row,col)->clearFlipOptions();
        }
    }
}

void GameLogic::switchPlayer(){
    Player *pSwap = this->player;
    this->player = this->rival;
    this->rival = pSwap;
};

int* GameLogic::getCurrentScore(){
    int arr[2]={player->getScore(),rival->getScore()};
    int *arrP;
    arrP=arr;
    return arrP;
}



