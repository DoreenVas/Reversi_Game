

#ifndef HW1_GAME_H
#define HW1_GAME_H
#include "GameLogic.h"
#include "Display.h"

/*****************************************************************************************************
* class name: Game
* description: runs the game
******************************************************************************************************/
class Game {
public:
/***************************************************************************************************
* constructor name:Game
* the input: a reference to the board and also the two players playing and the logic of the game
* the output: none
* the function operation:initializes the pointer fields                                 *
***************************************************************************************************/
    Game(Player *player1P,Player *player2P,Board *boardP, GameLogic *logicP ,Display *display);
/***************************************************************************************
* function name: play
* the input: none
* the output: none
* the function operation: runs the game
****************************************************************************************/
    void play();

private:
    Player *player;
    Player *rival;
    GameLogic *logic;
    Board *board;
    bool gameOn;//true if the game is still on
    Display *display;

/***************************************************************************************
* function name: swap
* the input: the players reference pointer
* the output: none
* the function operation: flips the playing and "watching" players
****************************************************************************************/
    void swap(Player *&player, Player *&rival);
};


#endif //HW1_GAME_H
