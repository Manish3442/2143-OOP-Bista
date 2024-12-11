## Making Class Design
### Name: Manish Bista
### Description: Desigining a set of classes for  a digital version of the game Knucklebones.


# Knucklebones Game Design

## Dice Class (Necessary)

### Data:
- `sides`: Number of sides on the dice.
- `current_value`: The current value of the dice.
- `color`: The color of the dice.

### Actions:
- `roll()`: Randomly assign a value to the dice based on the number of sides.
- `get_value()`: Return the current value of the die.
- `get_color()`: Return the color of the die.

### Relationships:
- A **Player** HAS-A **Dice** (composition).

---

## Stat Class (Wishful)

### Data:
- `games_played`: The number of games played by the player.
- `wins`: The number of wins the player has.
- `losses`: The number of losses the player has.
- `streak`: The player's current win/loss streak.
- `high_score`: The player's highest score achieved.

### Actions:
- `update_stats(won: bool)`: Updates the player’s statistics based on whether they won or lost.
- `reset_streak()`: Resets the player's win/loss streak.
- `check_high_score(current_score: int)`: Compares the current score with the high score and updates if necessary.

### Relationships:
- A **Player** HAS-A **Stat** (composition).

---

## Player Class (Necessary)

### Data:
- `name`: The name of the player.
- `score`: The player’s current score.
- `board`: The player’s grid for placing dice.
- `dice_set`: The set of dice the player is using.
- `stats`: The player's game statistics.
- `games_played`: The number of games the player has played.
- `selected_color`: The color chosen for the player's dice.

### Actions:
- `roll_dice()`: Roll a die for the player.
- `place_die(column)`: Place the die in the specified column of the player's grid.
- `get_score()`: Calculate and return the player’s current score based on the dice in the grid.
- `update_score()`: Recalculate the score when dice are added or removed.
- `remove_opponent_die(column, value)`: Remove a die from the opponent’s column if the player places a matching die.
- `choose_dice_color(color)`: Allows the player to select their dice color before the game starts.
- `update_stats(won: bool)`: Update the player’s statistics using methods from the **Stat** class.
- `set_active()`: Set the player's status to active.
- `set_inactive()`: Set the player's status to inactive.
- `send_message()`: Send a message to the other player.

### Relationships:
- A **Player** HAS-A **Dice**.
- A **Player** HAS-A **Stat** (composition).
- A **Player** interacts with the game by rolling dice and placing them on the grid.
- A **Player** interacts with **Chat** and **Game**.

---

## Game Class (Necessary)

### Data:
- `players`: The list of players in the game.
- `rules`: The rules governing the game.
- `current_round`: The current round of the game.
- `game_status`: The current status of the game (e.g., active, completed).
- `games_played`: The number of games played.
- `turn_start_time`: The start time of the player's turn.
- `turn_end_time`: The end time of the player's turn.
- `chat`: A chat system for in-game communication.
- `leaderboard`: A list of players and their scores.

### Actions:
- `start_game()`: Begin a new game session.
- `end_game()`: End the game and declare a winner.
- `get_winner()`: Determine and return the player with the highest score.
- `check_game_over()`: Check if the game has ended when both grids are full.
- `track_gameplay()`: Increase the `games_played` counter after each completed game.
- `start_turn_timer()`: Start the player's turn timer.
- `end_turn_timer()`: End the player's turn timer and calculate the duration.
- `update_leaderboard()`: Update the leaderboard at the end of the game.
- `send_message(sender, message)`: Send a chat message between players.

### Relationships:
- A **Game** HAS-A **Player** (composition).
- The **Game** controls player turns, time tracking, and communication.

---

## Chat Class (Wishful)

### Data:
- `messages`: The list of messages exchanged during the game.

### Actions:
- `send_message(sender, message)`: Send a message from one player to another.
- `get_chat_history()`: Retrieve the entire chat history.
- `clear_chat()`: Clear the chat log.

---

## Leaderboard Class (Possible)

### Data:
- `leaderboard`: A list of players and their scores.

### Actions:
- `update_leaderboard(player)`: Add or update the player’s score on the leaderboard.
- `get_leaderboard()`: Return the current leaderboard.

---

## Knucklebones Class (Inherits from Game)

### Data:
- `board`: The game board where dice are placed.
- `knucklebones_specific_rules`: Rules unique to Knucklebones.
- `color_bonuses`: Bonuses based on the color of the dice.
- `games_played`: The number of Knucklebones games played.

### Actions:
- `start_round()`: Begin a new round of Knucklebones.
- `end_round()`: End the current round and prepare for the next, if applicable.
- `calculate_winner()`: Use Knucklebones-specific rules to determine the winner, including multipliers and dice removal.

### Relationships:
- **Knucklebones** IS-A **Game** (inheritance).
- **Knucklebones** applies its own unique rules.
- A **Knucklebones** game tracks the number of games played (inherited from **Game**).
