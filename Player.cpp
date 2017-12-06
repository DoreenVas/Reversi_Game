
#include "Player.h"


Player::Player(char x):score(2),noMoves(false),disk(x) {

}

Player::Player(const Player &other){
    this->disk=other.disk;
    this->score=other.score;
    this->noMoves=other.noMoves;
}

char Player::getDisk() const {
    return disk;
}

void Player::setScore(int score) {
    Player::score += score;
}

int Player::getScore() const {
    return score;
}


bool Player::isNoMoves() const {
    return noMoves;
}

void Player::setNoMoves(bool noMoves) {
    Player::noMoves = noMoves;
}

void Player::possibleMovesVector(Board *board) {
    movesVec.erase(movesVec.begin(),movesVec.end()); //booting the vector to be empty
    for (int row = 0; row < board->getBoardSize(); row++) {
        for (int col = 0; col < board->getBoardSize(); col++) {
            if (board->cellAt(row,col)->isOption())
                movesVec.push_back(make_pair(row,col));
        }
    }
    if (!movesVec.empty())
        setNoMoves(false);
    else
        setNoMoves(true);

}


