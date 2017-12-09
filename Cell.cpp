
#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell():option(false),contains(Empty) {
    clearFlipOptions();
}

Contains Cell::getContains() const {
    return contains;
}

bool Cell::isOption()const {
    return option;
}

void Cell::setContains(Contains contains) {
    Cell::contains = contains;
}

void Cell::setOption(bool option) {
    Cell::option = option;
}

void Cell::changeFlipOptions(int row, int col, int sum) {
    flipOptions[row][col]=sum;
}

void Cell::clearFlipOptions() {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            flipOptions[i][j]=0;
}

const int Cell::getFlipOptions(int row,int col) const {
    return flipOptions[row][col];
}

const int Cell::getFlipSum() const {
    int sum=0;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            sum+=flipOptions[i][j];

    return sum;
}





