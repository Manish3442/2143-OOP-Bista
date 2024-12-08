#include "game_class.hpp"
#include <ncurses.h>

Game::Game() : dice() {
    // Explicitly initialize the players array
    players[0] = Player("Player 1");
    players[1] = Player("Player 2");

    current_player = &players[0];

    initscr();            // Initialize ncurses
    start_color();        // Enable colors
    init_pair(1, COLOR_RED, COLOR_BLACK);  // Player 1 grid color
    init_pair(2, COLOR_BLUE, COLOR_BLACK); // Player 2 grid color
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); // Dice roll color
    cbreak();             // Disable line buffering
    noecho();             // Prevent input echoing
    keypad(stdscr, TRUE); // Enable special keys
}

Game::~Game() {
    endwin(); // End ncurses
}

void Game::start() {
    while (!check_end_condition()) {
        display_game_state();

        // Prompt the player to roll the dice
        mvprintw(15, 0, "%s, press 'r' to roll the dice.", current_player->get_name().c_str());
        refresh();
        while (true) {
            int input = getch();
            if (input == 'r' || input == 'R') {
                break; // Proceed when the player presses 'r'
            } else {
                mvprintw(16, 0, "Invalid input! Press 'r' to roll the dice.");
                refresh();
            }
        }

        // Roll the dice
        roll_dice();

        // Ask the player where to place the dice
        int column = -1;
        mvprintw(20, 0, "Enter column (0-2) to place the number: ");
        refresh();
        while (true) {
            int input = getch();
            if (input >= '0' && input <= '2') {
                column = input - '0'; // Convert char to int
                if (place_die(*current_player, column)) {
                    break; // Valid move
                } else {
                    mvprintw(22, 0, "Column is full. Try a different column.");
                    refresh();
                }
            } else {
                mvprintw(22, 0, "Invalid input! Enter 0, 1, or 2.");
                refresh();
            }
        }

        // Switch turns
        switch_turn();
    }

    end_game();
}

void Game::roll_dice() {
    int value = dice.roll();
    attron(COLOR_PAIR(3));
    mvprintw(18, 0, "You rolled: %d", value);
    attroff(COLOR_PAIR(3));
    refresh();
}

bool Game::place_die(Player& player, int column) {
    return player.place_die(column, dice.get_face_value());
}

void Game::switch_turn() {
    current_player = (current_player == &players[0]) ? &players[1] : &players[0];
}

void Game::display_game_state() {
    clear();
    mvprintw(0, 0, "Game State:");
    players[0].display_grid(2, 0);  // Display Player 1's grid
    players[1].display_grid(10, 0); // Display Player 2's grid
    refresh();
}

bool Game::check_end_condition() {
    return players[0].is_grid_full() && players[1].is_grid_full();
}

void Game::end_game() {
    mvprintw(15, 0, "Game Over! Calculating scores...");
    int score1 = players[0].calculate_score();
    int score2 = players[1].calculate_score();

    mvprintw(16, 0, "Player 1 Score: %d", score1);
    mvprintw(17, 0, "Player 2 Score: %d", score2);

    if (score1 > score2) {
        mvprintw(18, 0, "Player 1 Wins!");
    } else if (score2 > score1) {
        mvprintw(18, 0, "Player 2 Wins!");
    } else {
        mvprintw(18, 0, "It's a tie!");
    }
    refresh();
    getch(); // Wait for a key press before exiting
}
