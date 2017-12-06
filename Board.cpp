

#include <iostream>
#include "Board.h"
using namespace std;


Board::Board() :
		m_BoardSize(defaultBoardSize)
{

	Board::setInitialState();
}

Board::Board(const size_t & i_BoardSize) :
	m_BoardSize((1 == i_BoardSize % 2) || (i_BoardSize < 4) ? 8 : i_BoardSize)
{
	Board::setInitialState();
}

//copy constructor
Board::Board(const Board &other){
    this->m_BoardSize=other.m_BoardSize;

    // Allocating exactly the same amount of cells to the new board.
    this->board = new Cell*[other.m_BoardSize];
    for (size_t i = 0; i < m_BoardSize; i++)
    {
    	this->board[i] = new Cell[m_BoardSize];
    }

    // Initiate the board's cells.
    for (size_t i = 0; i < m_BoardSize; i++)
    {
    	for (size_t j = 0; j < m_BoardSize; j++)
    	{
    		this->board[i][j].setContains(other.board[i][j].getContains());
    		this->board[i][j].setOption(other.board[i][j].isOption());
    		// initiate the directions member matrix.
    		for (size_t m = 0; m < 3; m++)
    		{
    			for (size_t n = 0; n < 3; n++)
    			{
    				this->board[i][j].changeFlipOptions(m,n,other.board[i][j].getFlipOptions(m,n));
    			}
    		}
    	}
    }
}
Board::~Board()
{
	for (size_t j = 0; j < m_BoardSize; j++) {
		delete[] board[j];
	}
	delete[] board;
}

void Board::setInitialState()
{
	// Initiate a dynamic board.
	board = new Cell*[m_BoardSize];
	for (size_t i = 0; i < m_BoardSize; ++i)
	{
		board[i] = new Cell[m_BoardSize];
	}

	size_t centerTopLeftRow = (m_BoardSize / 2) - 1;
	size_t centerTopLeftColumn = (m_BoardSize / 2) - 1;

	board[centerTopLeftRow][centerTopLeftColumn].setContains('o');
	board[centerTopLeftRow][centerTopLeftColumn].setOption(false);
	board[centerTopLeftRow + 1][centerTopLeftColumn + 1].setContains('o');
	board[centerTopLeftRow + 1][centerTopLeftColumn + 1].setOption(false);
	board[centerTopLeftRow][centerTopLeftColumn + 1].setContains('x');
	board[centerTopLeftRow][centerTopLeftColumn + 1].setOption(false);
	board[centerTopLeftRow + 1][centerTopLeftColumn].setContains('x');
	board[centerTopLeftRow + 1][centerTopLeftColumn].setOption(false);
}

size_t Board::getBoardSize() const
{
	return m_BoardSize;
}

void Board::printBoard() const {
    cout << " ";
    for (size_t i = 0; i < m_BoardSize; ++i) {
        cout << i + 1 << "  ";
    }
    cout << endl;

    for (int row = 0; row < m_BoardSize; row++) {
        cout << row + 1 << "|";
        for (int col = 0; col < m_BoardSize; col++) {
            cout << board[row][col].getContains() << "| ";
        }

        cout << endl << "..";
        for (size_t i = 0; i < m_BoardSize; i++) {
            cout << "...";
        }
        cout <<endl;

    }
}


Cell* Board::cellAt(int row, int col)const {
    return &board[row][col];
}


