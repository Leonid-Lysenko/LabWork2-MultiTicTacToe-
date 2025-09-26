/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file ConsoleOutput.cpp
 * @brief Implementation of the ConsoleOutput class for displaying game information in the console.
 */

#include "ConsoleOutput.h"
#include <iostream>

/**
 * @brief Displays the current state of the game board to the console.
 * 
 * Prints the board with 'X', 'O', or space for empty cells.
 * Rows and columns are separated by '|' and horizontal lines.
 * 
 * @param board The Board object representing the current game state.
 */
void ConsoleOutput::displayBoard(const Board& board) {
    std::cout << "\n";
    for (int row = 0; row < Board::SIZE; ++row) {
        for (int col = 0; col < Board::SIZE; ++col) {
            Cell cell = board.getCell(row, col);
            char symbol = (cell == Cell::X) ? 'X' : 
                         (cell == Cell::O) ? 'O' : ' ';
            std::cout << " " << symbol << " ";
            if (col < Board::SIZE - 1) std::cout << "|";
        }
        std::cout << "\n";
        if (row < Board::SIZE - 1) {
            std::cout << "-----------\n";
        }
    }
    std::cout << "\n";
}

/**
 * @brief Displays the current game state message.
 * 
 * Prints who won or if the game ended in a draw.
 * 
 * @param state The current GameState.
 */
void ConsoleOutput::displayGameState(GameState state) {
    switch (state) {
        case GameState::X_WON: 
            std::cout << "X won!\n"; 
            break;
        case GameState::O_WON: 
            std::cout << "O won!\n"; 
            break;
        case GameState::DRAW: 
            std::cout << "Draw!\n"; 
            break;
        default: 
            // For ongoing or exited states, no message is displayed
            break;
    }
}

/**
 * @brief Displays a generic message to the console.
 * 
 * @param message The message string to display.
 */
void ConsoleOutput::displayMessage(const std::string& message) {
    std::cout << message << "\n";
}

