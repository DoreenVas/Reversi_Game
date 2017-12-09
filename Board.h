

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include "Cell.h"
#include <cstdio>

/*****************************************************************************************************
* class name: Board
* description:each object is a board of the game reversi
******************************************************************************************************/
class Board {
public:
	/***************************************************************************************
	* constructor name: Board
	* the input: none
	* the output: none
	* the function operation: sets the beginning board
	****************************************************************************************/
	Board();

	/***************************************************************************************
	* constructor name: Board
	* the input: i_BoardSize
	* the output: none
	* the function operation: sets the beginning board and the board size to the size received if valid (else default size=8)
	****************************************************************************************/
	Board(const size_t & i_BoardSize);
	/***************************************************************************************
	* destructor name: Board
	* the input: none
	* the output: none
	*the function operation: used to free-up allocated dynamic board.
	****************************************************************************************/
	~Board();

	/***************************************************************************************
    * constructor name: Board
    * the input: other board
    * the output: none
    * the function operation: copy constructor, copies the board received
    ****************************************************************************************/
	Board(const Board &other);

	/***************************************************************************************
	* function name: printBoard
	* the input: none
	* the output:none
	* the function operation:prints a visual table of the board we created
	****************************************************************************************/
	void printBoard() const;

	/***************************************************************************************
	* function name: cellAt
	* the input: row and col
	* the output: a pointer to the cell which is located in (row,col) in the board
	* the function operation: access directly
	****************************************************************************************/
	Cell* cellAt(int row, int col)const;
	/***************************************************************************************
	* function name: setInitialState
	* the input: none
	* the output:none
	* the function operation: sets the initial state of the board
	****************************************************************************************/
	void setInitialState();
	/***************************************************************************************
	* function name: getBoardSize
	* the input: none
	* the output:size of the board
	* the function operation: access directly
	****************************************************************************************/
	size_t getBoardSize() const;


private:
	static const size_t defaultBoardSize=8;
	size_t m_BoardSize;
	Cell** board;

};


#endif //UNTITLED_BOARD_H
