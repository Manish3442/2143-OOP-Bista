# Knucklebones Dice Game  
### Your Name  

### Description:
Knucklebones is a turn-based dice game for two players where each player tries to outscore their opponent by strategically placing dice rolls in a 3x3 grid. The game uses a simple console-based interface built with `ncurses` to simulate dice rolls, grid management, and scoring.

Players roll a six-sided dice, then choose which column in their grid to place the rolled value. The goal is to maximize the score by strategically placing dice and filling the grid. The game ends when both players' grids are completely full, and the player with the highest score wins.

---

### Files

|   #   | File Name            | Description                                                |
| :---: | -------------------- | ---------------------------------------------------------- |
|   1   | [dice_class.cpp](./dice_class.cpp) | Implements a six-sided dice for generating random rolls. |
|   2   | [dice_class.hpp](./dice_class.hpp) | Header file for the Dice class.                         |
|   3   | [game_class.cpp](./game_class.cpp) | Contains the main game logic, such as turns, dice rolls, and grid management. |
|   4   | [game_class.hpp](./game_class.hpp) | Header file for the Game class.                         |
|   5   | [game.cpp](./game.cpp)             | Entry point for the program, starts the game loop.      |
|   6   | [grid_class.cpp](./grid_class.cpp) | Handles the grid logic, including dice placement and scoring. |
|   7   | [grid_class.hpp](./grid_class.hpp) | Header file for the Grid class.                         |
|   8   | [player_class.cpp](./player_class.cpp) | Implements the Player class for managing player-specific data and operations. |
|   9   | [player_class.hpp](./player_class.hpp) | Header file for the Player class.                       |
|  10   | [knucklebones](./knucklebones)    | Compiled binary file of the game (if applicable).       |

---

### Instructions  

To set up and run the game on your machine, follow these steps:

1. **Ensure the following dependencies are installed**:
   - A modern C++ compiler (e.g., g++, clang++)
   - `ncurses` library for terminal-based UI
   - `make` (if a Makefile is available for building)

2. **Build the project**:
   - If a Makefile is available:
     ```bash
     make
     ```
   - Otherwise, compile the files manually:
     ```bash
     g++ -o knucklebones game.cpp game_class.cpp grid_class.cpp player_class.cpp dice_class.cpp -lncurses
     ```

3. **Run the game**:
   ```bash
   ./knucklebones
