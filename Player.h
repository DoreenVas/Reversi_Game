

#ifndef HW1_PLAYER_H
#define HW1_PLAYER_H
#include "Board.h"
#include "GameLogic.h"
#include "Display.h"
#include <vector>
using namespace std;
#define PROBLEM -1
#define NO_MOVE -2
class GameLogic;

/*****************************************************************************************************
* class name: Player
* description: contains the possible Players in the game
******************************************************************************************************/
class Player{
public:
/***************************************************************************************************
* constructor name:Player
* the input: Contains x, Display object pointer display
* the output: none
* the function operation:initializes the score to (2),noMoves to (false),and disk to the type we got(x)                               *
***************************************************************************************************/
    explicit Player(Display *display,Contains x);
/***************************************************************************************************
* constructor name:Player
* the input: other player
* the output: none
* the function operation:it is a copy constructor of the player it got
***************************************************************************************************/
    Player(const Player &other);
/***************************************************************************************
* function name: isNoMoves
* the input: none
* the output: none
* the function operation: getter, true if the player has no moves, false otherwise.
****************************************************************************************/
    bool isNoMoves() const;
/***************************************************************************************
* function name: setNoMoves
* the input: boolian noMoves, if you have possible moves or not
* the output: none
* the function operation: setter
****************************************************************************************/
    void setNoMoves(bool noMoves);
/***************************************************************************************
* function name: getScore
* the input: none
* the output: none
* the function operation: getter, returns the players score
****************************************************************************************/
    int getScore() const;
/***************************************************************************************
* function name: setScore
* the input: none
* the output: none
* the function operation: sets the score to the variable it received
****************************************************************************************/
    void setScore(int score);
/***************************************************************************************
* function name: getType
* the input: none
* the output: none
* the function operation: returns the type of the player
****************************************************************************************/
    Contains getType() const;
/***************************************************************************************
* function name: preMovePrint (pure virtual)
* the input: board pointer
* the output: none
* the function operation: makes a print before the move is made
****************************************************************************************/
    virtual void preMovePrint(Board *board)=0;
/***************************************************************************************
* function name: postMovePrint (pure virtual)
* the input: board pointer
* the output: none
* the function operation: makes a print after the move is made
****************************************************************************************/
    virtual int postMovePrint(Board *board)=0;
/***************************************************************************************
* function name: chooseMove (pure virtual)
* the input: board, logic pointers
* the output: an array of 2 ints
* the function operation: return the row and col (in a pair) of the next move the player wants to make
****************************************************************************************/
    virtual pair<int,int> chooseMove(Board* board,GameLogic* logic)=0;
/***************************************************************************************
* function name: possibleMovesVector
* the input: pointer to the board
* the output: vector< pair<int,int> >
* the function operation:goes throw the board and for each cell if he's an option adds
* it to the vector.returns the vector.
****************************************************************************************/
    vector< pair<int,int> > possibleMovesVector(Board *board);
    pair<int,int> chosenMove;

protected:
    Display *display;
    Contains type;
    int score;
    bool noMoves;

};


#endif //HW1_PLAYER_H
