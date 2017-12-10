

#ifndef HW1_GAMELOGIC_H
#define HW1_GAMELOGIC_H

#include "Board.h"
#include "Player.h"
class Player;

/*****************************************************************************************************
* class name: GameLogic
* description: contains the rules of the game
******************************************************************************************************/
class GameLogic {
public:
/***************************************************************************************************
* constructor name:GameLogic
* the input: a reference to the board and also the two players playing
* the output: none
* the function operation:initializes the pointer fields
***************************************************************************************************/
    GameLogic(Player *player1P,Player  *player2P);
/***************************************************************************************************
* constructor name:GameLogic
* the input: a reference to another GameLogic object
* the output: none
* the function operation:copy constructor, copies the player and the rival objects by using their own copy constructors by type
***************************************************************************************************/
    GameLogic(const GameLogic &other);
/***************************************************************************************************
* destructor name:GameLogic
* the input: none
* the output: none
* the function operation:deletes the player and the rival objects to free the memory
***************************************************************************************************/
    ~GameLogic();
/***************************************************************************************
* function name:  possibleMoves (pure virtual)
* the input: none
* the output: none
* the function operation:in the DefaultLogic Class
****************************************************************************************/
    virtual void possibleMoves(Board *board)=0;

/***************************************************************************************
* function name:  resetPossibleMoves
* the input: board
* the output: none
* the function operation:for every cell in board the option is now false for a move and the flipOption table is initialized
****************************************************************************************/
    void resetPossibleMoves(Board *board);
/***************************************************************************************
* function name:  makeMove (pure virtual)
* the input: none
* the output: none
* the function operation:in the DefaultLogic Class
****************************************************************************************/
    virtual void makeMove(int row, int col,Board *board)=0;
/***************************************************************************************
* function name:  switchPlayer
* the input: none
* the output: none
* the function operation:switches between the player and the rival pointers to change who is currently playing
****************************************************************************************/
    void switchPlayer();
/***************************************************************************************
* function name:  getCurrentScore
* the input: none
* the output: int array size 2
* the function operation:returns the score of each player by direct access
****************************************************************************************/
    int* getCurrentScore();

protected:
    Player *player;// the player currently playing
    Player *rival;// the player in "stand by"

};


#endif //HW1_GAMELOGIC_H
