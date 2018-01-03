

#ifndef HW1_CONSOLEDISPLAY_H
#define HW1_CONSOLEDISPLAY_H

#include "Display.h"
/*****************************************************************************************************
* class name: ConsoleDisplay
* description: prints the game to the console
******************************************************************************************************/
class ConsoleDisplay : public Display{
public:
    //all has description in Display.h
    void printBoard(Board *board) const;
    void printChosenMove(pair<int,int> chosenMove,Contains type) const;
    void printEnd(Contains type,int playerScore, int rivalScore)const;
    void printMessage(const string message) const;
    virtual void noMoves(Contains type) const;
    int getOpponentType() const;
    void printPossibleMoves( vector<pair<int, int> > movesVec)const;
    void yourMove(Contains type) const;
    void enterMove()const;
    int getCommand() const;
    string chooseName() const;


private:
    /***************************************************************************************
    * function name: playerDisk
    * the input:  Contains type
    * the output: a char 'X' or 'O'
    * the function operation:checks the player's type and return the correct disk: Black='X', White='O'
    ****************************************************************************************/
    char playerDisk(Contains type)const;
};


#endif //HW1_CONSOLEDISPLAY_H
