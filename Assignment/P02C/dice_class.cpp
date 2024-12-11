#include "dice_class.hpp"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    std::srand(std::time(0)); // Seed for random number generator
    current_value = 0;
}

int Dice::roll() {
    current_value = (std::rand() % 6) + 1; // Generate a number between 1 and 6
    return current_value;
}

int Dice::get_face_value() const {
    return current_value;
}
