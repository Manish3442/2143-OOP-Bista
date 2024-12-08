#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include <string>
#include "grid_class.hpp"

class Player {
public:
    Player();                          // Default constructor
    Player(const std::string& name);   // Parameterized constructor

    bool place_die(int column, int value);
    void display_grid(int y, int x) const;
    int calculate_score() const;
    bool is_grid_full() const;
    std::string get_name() const;

private:
    std::string name;                  // Player's name
    Grid player_grid;                  // Player's grid
};

#endif

