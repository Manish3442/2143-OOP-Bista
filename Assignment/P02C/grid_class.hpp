#ifndef GRID_CLASS_HPP
#define GRID_CLASS_HPP

class Grid {
public:
    Grid();                              // Constructor

    bool place_dice(int column, int value); // Places dice in the given column
    void display(int y, int x) const;    // Displays the grid at the given position
    int calculate_score() const;         // Calculates the total score
    bool is_full() const;                // Checks if the grid is full

private:
    int cells[3][3];                     // 3x3 grid for dice values
};

#endif
