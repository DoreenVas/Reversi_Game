
#ifndef HW1_DISPLAY_H
#define HW1_DISPLAY_H

#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;
/*****************************************************************************************************
* class name: Display
* description: in charge of displaying the game to the players
******************************************************************************************************/
class Display {
public:
    /***************************************************************************************
    * function name: printBoard
    * the input: Board *board
    * the output:prints a visual table of the board we created
    * the function operation:goes throw every cell in the board
    ****************************************************************************************/
    virtual void printBoard(Board *board) const=0;
    /***************************************************************************************
     * function name: printChosenMove
     * the input: the chosen pair and the type of the player
     * the output:prints the chosen move according to the player who played it
     * the function operation:direct access
     ****************************************************************************************/
    virtual void printChosenMove(pair<int,int> chosenMove,Contains type) const=0;
    /***************************************************************************************
    * function name: printEnd
    * the input: Contains type,int playerScore, int rivalScore
    * the output: prints the winner and the score
    * the function operation: checks to see who won and prints accordingly
    ****************************************************************************************/
    virtual void printEnd(Contains type,int playerScore, int rivalScore)const=0;
    /***************************************************************************************
    * function name: printMessage
    * the input: const string message
    * the output: prints the message
    * the function operation: direct access
    ****************************************************************************************/
    virtual void printMessage(const string message) const=0;
    /***************************************************************************************
   * function name: noMoves
   * the input: Contains type
   * the output: prints to the player he has no moves
   * the function operation: according to the player's type prints the correct output
   ****************************************************************************************/
    virtual void noMoves(Contains type) const=0;
    /***************************************************************************************
    * function name: getOpponentType
    * the input: none
    * the output: the number the player chose (1/2/3)
    * the function operation: takes input from the console and returns the number
    ****************************************************************************************/
    virtual int getOpponentType() const=0;
    /***************************************************************************************
    * function name: printPossibleMoves
    * the input:  vector<pair<int, int> > movesVec
    * the output: prints the possible moves the player has
    * the function operation:goes throw the vector of valid moves and prints each  move
    ****************************************************************************************/
    virtual void printPossibleMoves( vector<pair<int, int> > movesVec)const=0;
    /***************************************************************************************
   * function name: yourMove
   * the input:  Contains type
   * the output: informs the player it's his turn
   * the function operation:prints according to the type received
   ****************************************************************************************/
    virtual void yourMove(Contains type) const=0;
    /***************************************************************************************
    * function name: enterMove
    * the input:  none
    * the output: prints request to make move
    * the function operation:directly
    ****************************************************************************************/
    virtual void enterMove()const=0;
    /***************************************************************************************
   * function name: getCommand
   * the input: none
   * the output: the number the player chose (1/2/3)
   * the function operation: takes input from the console and returns the number
   ****************************************************************************************/
    virtual int getCommand() const=0;
    /***************************************************************************************
    * function name: chooseName
     * the input: none
     * the output: name for game
     * the function operation: takes input from the console and returns the string
     ****************************************************************************************/
    virtual string chooseName() const=0;

};


#endif //HW1_DISPLAY_H
