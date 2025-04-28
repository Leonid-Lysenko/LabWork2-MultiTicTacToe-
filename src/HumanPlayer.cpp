/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file HumanPlayer.cpp
 * @brief Implementation of the HumanPlayer class handling human input.
 */

#include "HumanPlayer.h"
#include <iostream>

/**
 * @brief Constructs a HumanPlayer with the specified marker and input handler.
 * @param marker The player's marker (X or O).
 * @param inputHandler Shared pointer to an InputHandler for receiving user input.
 */
HumanPlayer::HumanPlayer(Cell marker, std::shared_ptr<InputHandler> inputHandler) 
    : Player(marker, inputHandler) {}

/**
 * @brief Gets a valid move from the human player in classic 2D mode.
 * 
 * Continuously prompts the user for input until a valid move is entered or exit is requested.
 * Handles exceptions and invalid moves gracefully.
 * 
 * @param board The current game board.
 * @return A valid Move chosen by the player.
 * @throws std::runtime_error if the player requests to exit.
 */
Move HumanPlayer::getMove(const Board& board) {
    while (true) {
        try {
            if (shouldExit()) {
                throw std::runtime_error("Game exit requested");
            }
            
            Position pos = inputHandler->getInput();
            Move move(pos, marker);
            
            if (board.isMoveValid(move)) {
                return move;
            } else {
                std::cout << "Invalid move! Try again.\n";
            }
        } catch (const std::exception& e) {
            if (shouldExit()) throw;
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

/**
 * @brief Gets a valid move from the human player in 3D mode.
 * 
 * Continuously prompts the user for 3D input until a valid move is entered or exit is requested.
 * Handles exceptions and invalid moves gracefully.
 * 
 * @param board The current 3D game board.
 * @return A valid Position3D chosen by the player.
 * @throws std::runtime_error if the player requests to exit.
 */
Position3D HumanPlayer::get3DMove(const Board3D& board) {
    while (true) {
        try {
            if (shouldExit()) {
                throw std::runtime_error("Game exit requested");
            }
            
            Position3D pos = inputHandler->get3DInput();
            Move move(pos.position, marker);
            
            if (board.isMoveValid(pos.level, move)) {
                return pos;
            } else {
                std::cout << "Invalid move! Try again.\n";
            }
        } catch (const std::exception& e) {
            if (shouldExit()) throw;
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

