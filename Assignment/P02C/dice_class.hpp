#ifndef DICE_CLASS_HPP
#define DICE_CLASS_HPP

class Dice {
public:
    Dice();                // Constructor
    int roll();            // Rolls the dice (1-6)
    int get_face_value() const; // Returns the last rolled value

private:
    int current_value;     // Stores the last rolled dice value
};

#endif
