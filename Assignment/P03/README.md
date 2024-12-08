# Knucklebones Game

### By: [Manish Bista]

## Description

**Knucklebones** is a two-player dice game where players roll dice and place them in a 3x3 grid. The game incorporates a fun, engaging dice-rolling animation, alternating turns between two players, and calculating scores based on dice placement in the grid. The player with the highest score at the end of the game wins.

Key features of the game:
- **Dice Rolling Animation**: The dice is animated as it rolls across the screen.
- **Turn-Based**: Players take turns rolling dice and placing them in the grid.
- **Scoring System**: Points are awarded for placing dice in the grid, with a bonus for stacking identical dice values.
- **Player Input**: Players use the keyboard to roll the dice and place the dice in one of three columns.

This project uses **SFML** for graphics rendering and animation.

## Files

|   #   | File            | Description                                                                 |
| :---: | --------------- | --------------------------------------------------------------------------- |
|   1   | `Main.cpp`       | Main entry point of the game, initializes the window and handles game loop. |
|   2   | `Game.cpp`       | Contains the core logic of the game, including dice roll animation and turn management. |
|   3   | `Game.h`         | Header file for the `Game` class, declaring methods for the game logic.      |
|   4   | `Player.cpp`     | Handles player-related logic, including grid management and score calculation. |
|   5   | `Player.h`       | Header file for the `Player` class, declaring methods for grid and score management. |
|   6   | `README.md`      | This file, describing the project and how to run it.                        |

## Instructions

### **Prerequisites**

- **SFML**: This project uses the SFML library for rendering graphics, so you'll need to have it installed on your system.

#### **To Install SFML**:
- **macOS**: Use Homebrew:
  ```bash
  brew install sfml
## Compilation and Running
  make
  
  ./knucklebones
  
  make clean
