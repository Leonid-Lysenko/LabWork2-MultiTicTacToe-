/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file main.cpp
 * @brief Main application file for Tic-Tac-Toe game.
 */

#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "EasyAIDifficulty.h"
#include "MediumAIDifficulty.h"
#include "HardAIDifficulty.h"
#include <memory>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

/**
 * @brief Reads an integer input safely from the console within a specified range.
 * 
 * Continuously prompts the user until a valid integer within [min, max] is entered.
 * 
 * @param prompt The prompt message to display.
 * @param min Minimum acceptable value.
 * @param max Maximum acceptable value.
 * @return The validated integer input.
 */
int readIntInput(const std::string& prompt, int min, int max) {
    int value;
    std::string input;
    
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        std::istringstream iss(input);
        if (iss >> value) {
            char remaining;
            if (iss >> remaining) {
                std::cout << "Error: please enter an integer, not '" << input << "'" << std::endl;
                continue;
            }
            
            if (value >= min && value <= max) {
                return value;
            } else {
                std::cout << "Error: number must be between " << min << " and " << max << std::endl;
            }
        } else {
            std::cout << "Error: please enter an integer, not '" << input << "'" << std::endl;
        }
    }
}

/**
 * @brief Main function - entry point of the application.
 * 
 * Sets up the game mode, player types (human or AI), AI difficulty, and starts the game loop.
 * 
 * @return Exit status code.
 */
int main() {
    // Create shared input and output handlers
    auto input = std::make_shared<ConsoleInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    // Select game mode: Classic or 3D
    output->displayMessage("Select game mode:");
    output->displayMessage("1 - Classic Tic-Tac-Toe");
    output->displayMessage("2 - 3D Tic-Tac-Toe");
    int modeChoice = readIntInput("Your choice: ", 1, 2);
    
    Game::Mode mode = (modeChoice == 1) ? Game::Mode::CLASSIC : Game::Mode::THREE_D;

    // Select game type: vs AI or two players
    output->displayMessage("Select game type:");
    output->displayMessage("1 - Play against AI");
    output->displayMessage("2 - Two players");
    int gameType = readIntInput("Your choice: ", 1, 2);

    // Create first player (always human, X)
    std::unique_ptr<Player> player1 = std::make_unique<HumanPlayer>(Cell::X, input);
    std::unique_ptr<Player> player2;

    if (gameType == 1) {
        // AI difficulty selection
        output->displayMessage("Select AI difficulty:");
        output->displayMessage("1 - Easy");
        output->displayMessage("2 - Medium");
        output->displayMessage("3 - Hard");
        
        int difficultyChoice = readIntInput("Your choice: ", 1, 3);
        
        std::unique_ptr<AIDifficulty> difficulty;
        switch (difficultyChoice) {
            case 1: difficulty = std::make_unique<EasyAIDifficulty>(); break;
            case 2: difficulty = std::make_unique<MediumAIDifficulty>(); break;
            case 3: difficulty = std::make_unique<HardAIDifficulty>(); break;
        }
        // Create AI player with O marker
        player2 = std::make_unique<AIPlayer>(Cell::O, std::move(difficulty));
    } else {
        // Two human players
        player2 = std::make_unique<HumanPlayer>(Cell::O, input);
    }

    // Initialize and start the game
    Game game(std::move(player1), std::move(player2), output, mode);
    game.start();

    return 0;
}

