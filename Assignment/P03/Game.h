#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include <chrono>

class Game {
private:
    sf::RenderWindow& window;
    sf::RectangleShape rollButton; 
    sf::Text rollButtonText;  
    Player player1;
    Player player2;
    bool player1Turn;

    // Dice Animation Variables
    std::vector<sf::Texture> animationFrames; // Rolling frames
    std::vector<sf::Texture> diceFaces;       // Final dice faces
    sf::Sprite diceSprite;
    bool animationRunning;
    int frameIndex;
    sf::Clock animationClock;
    int diceValue;

    sf::Font font;
    sf::Text infoText;

    void handleInput();
    void updateGrid(Player& player, int column, int row);
    void drawGrid(const Player& player, int offsetX, int offsetY);
    void drawText(const std::string& text, int x, int y, sf::Color color);

public:
    Game(sf::RenderWindow& win);
    void rollDice();
    void run(); 
    void draw();  
    bool isGameOver() const;               
private:
    void updateDiceAnimation(); 
    
};

#endif


