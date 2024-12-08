#include "player_class.hpp"
#include <ncurses.h> // Include ncurses for mvprintw

Player::Player() : name("Unnamed"), player_grid() {}

Player::Player(const std::string& name) : name(name), player_grid() {}

bool Player::place_die(int column, int value) {
    return player_grid.place_dice(column, value);
}

void Player::display_grid(int y, int x) const {
    mvprintw(y, x, "%s's Grid:", name.c_str());
    player_grid.display(y + 1, x);
}

int Player::calculate_score() const {
    return player_grid.calculate_score();
}

bool Player::is_grid_full() const {
    return player_grid.is_full();
}

std::string Player::get_name() const {
    return name;
}

