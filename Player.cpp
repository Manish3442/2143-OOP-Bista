#include <iostream>
#include "Player.h"
#include <unordered_map>


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

int Player::removeOpponentDice(int row, int column, int diceValue) {
    if (grid[row][column] == diceValue) { // Check if the specific box contains the matching value
        grid[row][column] = 0; // Remove the die
        std::cout << "Removed dice of value " << diceValue
                  << " from row " << row + 1 << ", column " << column + 1 << std::endl;
        return row; // Indicate that the die was successfully removed
    }
    return -1; // Indicate that no dice were removed
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
    for (int col = 0; col < 3; ++col) {
        std::unordered_map<int, int> diceCount; // To count occurrences of dice values
        for (int row = 0; row < 3; ++row) {
            int value = grid[row][col];
            if (value != 0) {
                diceCount[value]++;
            }
        }
        // Calculate column score with multipliers
        for (const auto& pair : diceCount) {
            score += pair.first * pair.second * pair.second; // Multiplier: value * occurrences^2
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
