

#ifndef HW1_CELL_H
#define HW1_CELL_H
/*****************************************************************************************************
* class name: Cell
* description: each object is a cell inside board
******************************************************************************************************/
enum Contains {Black,White,Empty};

class Cell {
public:
/***************************************************************************************************
* constructor name: Cell
* the input: none
* the output: none
* the function operation:makes the cell option false,the default value ' ' and calls clearFlipOptions();                                  *
***************************************************************************************************/
    Cell();
/***************************************************************************************
* function name: setContains
* the input: Contains contains
* the output: none
* the function operation: changes the cell value according to the value it receives
****************************************************************************************/
    void setContains( Contains contains);
/***************************************************************************************
* function name: getContains
* the input: none
* the output: the value of the cell
* the function operation: access directly
****************************************************************************************/
    Contains getContains()const ;
/***************************************************************************************
* function name: isOption
* the input: none
* the output: true if putting a disk is a legal move, otherwise false
* the function operation: access directly
****************************************************************************************/
    bool isOption()const;
/***************************************************************************************
* function name: setOption
* the input: a boolian value
* the output: none
* the function operation: access directly and change
****************************************************************************************/
    void setOption(bool option);
/***************************************************************************************
* function name: changeFlipOptions
* the input: row, col in in the flipOption 3x3 table and the sum=the number of moves that can be made in that direction
* the output: none
* the function operation: access directly to the 3x3 board and changes the sum
****************************************************************************************/
    void changeFlipOptions(int row,int col,int sum);
/***************************************************************************************
* function name: clearFlipOptions
* the input: none
* the output: none
* the function operation: goes over the table directly and makes every cell equal to zero
****************************************************************************************/
    void clearFlipOptions();
/***************************************************************************************
* function name: getFlipOptions
* the input: row and col in the flipOptions table
* the output: the sum of moves you can make in that direction
* the function operation: access directly and returns
****************************************************************************************/
    const int getFlipOptions(int row,int col) const;


/***************************************************************************************
* function name: getFlipSum
* the input: none
* the output: the sum of disks you can flip from all directions
* the function operation: goes throw the flipOptions array and adds each direction flips to the sum
****************************************************************************************/
    const int getFlipSum() const;
private:
    bool option; // true if it's possible to put a disk there, otherwise false
    Contains contains; //  Black/White/Empty
    int flipOptions[3][3]; //the number of rival disks you can change in each direction. you put the disk in the
    // middle so all the direction are the same as represented around you

};


#endif //HW1_CELL_H
