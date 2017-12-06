
#ifndef HW1_DEFAULTLOGIC_H
#define HW1_DEFAULTLOGIC_H

#include "GameLogic.h"
/*****************************************************************************************************
* class name: DefaultLogic
* description: contains the default rules of the game
******************************************************************************************************/
class DefaultLogic: public GameLogic {
public:
/***************************************************************************************************
* constructor name: DefaultLogic
* the input: gets a reference to the board and the two players playing
* the output: none
* the function operation:calls GameLogic constructor
***************************************************************************************************/
    DefaultLogic(Player *player1P,Player  *player2P);

/***************************************************************************************************
* constructor name: DefaultLogic
* the input: gets a reference to another board
* the output: none
* the function operation:it's a copy constructor which calls GameLogic copy constructor
***************************************************************************************************/
    DefaultLogic(const GameLogic &other);

/***************************************************************************************
* function name:  possibleMoves
* the input: none
* the output: none
* the function operation: goes throw the Cells in board and if she sees a player disk she calls checkCell for that cell
****************************************************************************************/
    void possibleMoves(Board *board);
/***************************************************************************************
* function name:  makeMove
* the input: row and col of the location the move is made in
* the output: none
* the function operation:puts the players disk in place and +1 to his score,than goes throw
* the cell flipOption and changes "sum" disks in each direction and changes accordingly the score
****************************************************************************************/
    void makeMove(int row, int col,Board *board);

private:
    /***************************************************************************************
* function name:  checkCell
* the input: row and col of the cell we are checking
* the output: none
* the function operation: checks the close cell in each direction to see if it
* contains the rival disk. if so sends it to checkDirection
****************************************************************************************/
    void checkCell(int row, int col,Board *board);
/***************************************************************************************
* function name:  checkDirection
* the input: row and col of the cell we are checking and also the delta so we know which way to check
* the output: none
* the function operation:while we see a rival disk we continue in that way,if it ends with a space we
* set the cell option to true and update the changeFlipOptions with the sum we reached.
****************************************************************************************/
    void checkDirection(int row,int col,int deltaRow,int deltaCol,Board *board);

};


#endif //HW1_DEFAULTLOGIC_H
