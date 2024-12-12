#include "grid_class.hpp"
#include <ncurses.h>

Grid::Grid() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j] = 0; // Initialize grid to 0
}

bool Grid::place_dice(int column, int value) {
    if (column < 0 || column >= 3) return false; // Invalid column

    for (int i = 0; i < 3; ++i) {
        if (cells[i][column] == 0) { // Place dice in the first empty row
            cells[i][column] = value;
            return true;
        }
    }
    return false; // Column is full
}

void Grid::display(int y, int x) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mvprintw(y + i, x + j * 4, "[%d]", cells[i][j]);
        }
    }
}

int Grid::calculate_score() const {
    int score = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            score += cells[i][j]; // Sum up all dice values
        }
    }
    return score;
}

bool Grid::is_full() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (cells[i][j] == 0) return false; // Empty cell found
    return true; // All cells are full
}

