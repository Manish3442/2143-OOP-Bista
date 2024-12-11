#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player {
private:
    std::vector<std::vector<int>> grid;

public:
    Player();
    int placeDice(int column, int diceValue);
    int removeOpponentDice(int row, int column, int diceValue); // Updated declaration
    bool isColumnFull(int column) const;
    bool isGridFull() const;
    int calculateScore() const;
    int getGridValue(int row, int col) const;

    void setGridValue(int row, int col, int value);
};

#endif
