## Making Class Design
### Name: Manish Bista
### Description: Desigining a set of classes for  a digital version of the game Knucklebones.


1. Dice Class (Necessary)
Data:
•	sides
•	Current_value
•	color

Actions:
•	roll (): Randomly assign a value to the dice based on the number of sides.
•	get_value (): Return the current value of the die.
•	get_color (): Return the color of the die.

Relationships:
•	A Player HAS-A Dice (composition).
 
2. Stat Class (Wishful)
Data:
•	games_played
•	wins
•	losses
•	streak
•	high_score

Actions:
•	update_stats(won: bool): Updates the player’s statistics 
•	reset_streak(): Resets the win/loss streak.
•	check_high_score(current_score: int): Checks the current score against the high score and updates it if the current score is higher.

Relationships:
•	A Player HAS-A Stat (composition).
 
3. Player Class (Necessary)
Data:
•	name
•	score
•	board
•	dice_set
•	stats
•	games_played
•	selected_color
•	

Actions:
•	roll_dice(): Roll a die for the player.
•	place_die(column): Place the die in the specified column of the player's grid.
•	get_score(): Calculate and return the player’s current score based on the dice in the grid.
•	update_score(): Recalculate the score when dice are added or removed.
•	remove_opponent_die(column, value): Remove a die from the opponent’s column if the player places a matching die.
•	choose_dice_color(color): Allows the player to select their dice color before the game starts.
•	update_stats(won: bool): Update the player’s statistics using the methods from the Stat class.
•	set_active (): Set player status to active.
•	 set_inactive (): Set player to active.
•	Send_message (): Send a message to the other player.

Relationships:
•	A Player HAS-A Dice.
•	A Player HAS-A Stat (composition).
•	A Player interacts with the game by rolling dice and placing them on the grid.
•	A player interacts with Chat and Game.
 
4. Game Class (Nec
Data:
•	players
•	rules
•	current_round
•	game_status
•	games_played
•	game_status
•	turn_start_time
•	turn_end_time
•	chat
•	leaderboard

Actions:
•	start_game(): Begin a new game session.
•	end_game(): End the game and declare a winner.
•	get_winner(): Determine and return the player with the highest score.
•	check_game_over(): Check if the game has ended when both grids are full.
•	track_gameplay(): Increase the games_played counter after each completed game.
•	start_turn_timer(): Start the player's turn timer.
•	end_turn_timer(): End the player's turn timer and calculate duration.
•	update_leaderboard(): Update the leaderboard at the end of the game.
•	send_message(sender, message): Send a chat message between players.
Relationships:
•	A Game HAS-A Player (composition).
•	The Game controls player turns, time tracking, and communication.
 
3. Chat Class (Wishful)
Data:
•	Messages

Actions:
•	send_message(sender, message): Send a message from one player to another.
•	get_chat_history(): Retrieve the entire chat history.
•	clear_chat(): Clear the chat log.
 
4. Leaderboard Class (Possible)
Data:
•	leaderboard

Actions:
•	update_leaderboard(player): Add or update the player’s score.
•	get_leaderboard(): Return the current leaderboard.

5. Knucklebones Class (Inherits from Game)
Data:
•	board
•	knucklebones_specific_rules
•	color_bonuses
•	games_played

Actions:
•	start_round(): Begin a new round of Knucklebones.
•	end_round(): End the current round and prepare for the next, if applicable.
•	calculate_winner(): Use Knucklebones-specific rules to determine the winner, including multipliers, and dice removal.
Relationships:
•	Knucklebones IS-A Game (inheritance).
•	Knucklebones applies its own unique rules.
•	A Knucklebones game tracks the number of games played (inherited from Game).
 

