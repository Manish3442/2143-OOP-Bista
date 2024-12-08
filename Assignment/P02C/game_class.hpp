#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "dice_class.hpp"
#include "player_class.hpp"

class Game {
public:
    Game();                       // Constructor
    ~Game();                      // Destructor

    void start();                 // Starts the game
    void roll_dice();             // Rolls the dice
    bool place_die(Player& player, int column); // Places the die in the player's grid
    void display_game_state();    // Displays the current state of the game
    bool check_end_condition();   // Checks if the game is over
    void end_game();              // Displays the game results

private:
    Dice dice;                    // Dice object
    Player players[2];            // Two players
    Player* current_player;       // Pointer to the current player

    void switch_turn();           // Switches the turn to the next player
};

#endif
