#include "Player.h"

Player::Player() : grid(3, std::vector<int>(3, 0)) {}

int Player::placeDice(int column, int diceValue) {
    for (int row = 2; row >= 0; --row) {
        if (grid[row][column] == 0) {
            grid[row][column] = diceValue;
            return row;
        }
    }
    return -1;
}

int Player::removeOpponentDice(int column, int diceValue) {
    for (int row = 0; row < 3; ++row) {
        if (grid[row][column] == diceValue) {
            grid[row][column] = 0;
            return row;
        }
    }
    return -1;
}

bool Player::isColumnFull(int column) const {
    return grid[0][column] != 0;
}

bool Player::isGridFull() const {
    for (int col = 0; col < 3; ++col) {
        if (!isColumnFull(col)) return false;
    }
    return true;
}

int Player::calculateScore() const {
    int score = 0;
    for (const auto& row : grid) {
        for (int value : row) {
            score += value; // Sum all dice values
        }
    }
    
    return score;
}

int Player::getGridValue(int row, int col) const {
    return grid[row][col];
}
void Player::setGridValue(int row, int col, int value) {
    grid[row][col] = value;
}
