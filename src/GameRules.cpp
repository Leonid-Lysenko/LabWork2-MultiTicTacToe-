/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file GameRules.cpp
 * @brief Implementation of the GameRules class that checks game conditions.
 */

#include "GameRules.h"

/**
 * @brief Checks if the specified player has won on the given board.
 * 
 * The method checks all rows, columns, and diagonals for a winning line.
 * 
 * @param board The current game board.
 * @param marker The player's marker (Cell::X or Cell::O).
 * @return true if the player has a winning line, false otherwise.
 */
bool GameRules::checkWin(const Board& board, Cell marker) const {
    auto grid = board.getGrid();

    // Check all rows and columns
    for (int i = 0; i < Board::SIZE; ++i) {
        // Check row i
        if (grid[i][0] == marker && grid[i][1] == marker && grid[i][2] == marker) {
            return true;
        }
        // Check column i
        if (grid[0][i] == marker && grid[1][i] == marker && grid[2][i] == marker) {
            return true;
        }
    }

    // Check main diagonal
    if (grid[0][0] == marker && grid[1][1] == marker && grid[2][2] == marker) {
        return true;
    }
    // Check anti-diagonal
    if (grid[0][2] == marker && grid[1][1] == marker && grid[2][0] == marker) {
        return true;
    }

    // No winning line found
    return false;
}

/**
 * @brief Checks if the game has ended in a draw.
 * 
 * A draw occurs when the board is full and neither player has won.
 * 
 * @param board The current game board.
 * @return true if the game is a draw, false otherwise.
 */
bool GameRules::checkDraw(const Board& board) const {
    return board.isFull() && 
           !checkWin(board, Cell::X) && 
           !checkWin(board, Cell::O);
}

