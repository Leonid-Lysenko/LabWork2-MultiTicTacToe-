/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Board3D.cpp
 * @brief Implementation of the Board3D class representing a 3D tic-tac-toe board.
 */

#include "Move.h"
#include "Board3D.h"
#include "GameRules.h"
#include <algorithm>

/**
 * @brief Default constructor for Board3D.
 * 
 * Initializes the 3D board with default-constructed 2D boards.
 */
Board3D::Board3D() = default;

/**
 * @brief Checks if a move is valid on the specified level.
 * 
 * @param level The level index (0-based).
 * @param move The move to validate.
 * @return true if the move is valid on the given level, false otherwise.
 */
bool Board3D::isMoveValid(int level, const Move& move) const {
    return level >= 0 && level < LEVELS && 
           levels[level].isMoveValid(move);
}

/**
 * @brief Applies a move on the specified level.
 * 
 * Sets the cell at the move's position to the player's marker.
 * 
 * @param level The level index (0-based).
 * @param move The move to apply.
 */
void Board3D::makeMove(int level, const Move& move) {
    levels[level].setCell(move.position.row, move.position.col, move.player);
}

/**
 * @brief Checks if the specified player has won on the 3D board.
 * 
 * This method checks all 49 possible winning lines in 3D tic-tac-toe:
 * - 27 lines on each level (rows, columns, diagonals)
 * - 9 vertical lines across levels
 * - 12 spatial diagonals crossing levels and positions
 * 
 * @param player The player marker to check for a win.
 * @return true if the player has a winning line, false otherwise.
 */
bool Board3D::checkWin(Cell player) const {
    // 1. Check rows, columns, and diagonals on each level (27 checks)
    for (int level = 0; level < LEVELS; ++level) {
        // Rows
        for (int row = 0; row < Board::SIZE; ++row) {
            if (levels[level].getCell(row, 0) == player &&
                levels[level].getCell(row, 1) == player &&
                levels[level].getCell(row, 2) == player) {
                return true;
            }
        }

        // Columns
        for (int col = 0; col < Board::SIZE; ++col) {
            if (levels[level].getCell(0, col) == player &&
                levels[level].getCell(1, col) == player &&
                levels[level].getCell(2, col) == player) {
                return true;
            }
        }

        // Diagonals on the level
        if (levels[level].getCell(0, 0) == player &&
            levels[level].getCell(1, 1) == player &&
            levels[level].getCell(2, 2) == player) {
            return true;
        }

        if (levels[level].getCell(0, 2) == player &&
            levels[level].getCell(1, 1) == player &&
            levels[level].getCell(2, 0) == player) {
            return true;
        }
    }

    // 2. Check vertical lines across levels (9 checks)
    for (int row = 0; row < Board::SIZE; ++row) {
        for (int col = 0; col < Board::SIZE; ++col) {
            if (levels[0].getCell(row, col) == player &&
                levels[1].getCell(row, col) == player &&
                levels[2].getCell(row, col) == player) {
                return true;
            }
        }
    }

    // 3. Check all spatial diagonals (12 checks)

    // Main spatial diagonals (4)
    if (levels[0].getCell(0, 0) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(2, 2) == player) {
        return true;
    }

    if (levels[0].getCell(0, 2) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(2, 0) == player) {
        return true;
    }

    if (levels[0].getCell(2, 0) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(0, 2) == player) {
        return true;
    }

    if (levels[0].getCell(2, 2) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(0, 0) == player) {
        return true;
    }

    // Diagonals with level and row/column changes (8 additional)
    if (levels[0].getCell(0, 0) == player &&
        levels[1].getCell(1, 0) == player &&
        levels[2].getCell(2, 0) == player) {
        return true;
    }

    if (levels[0].getCell(0, 1) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(2, 1) == player) {
        return true;
    }

    if (levels[0].getCell(0, 2) == player &&
        levels[1].getCell(1, 2) == player &&
        levels[2].getCell(2, 2) == player) {
        return true;
    }

    if (levels[0].getCell(1, 0) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(1, 2) == player) {
        return true;
    }

    if (levels[0].getCell(2, 0) == player &&
        levels[1].getCell(1, 0) == player &&
        levels[2].getCell(0, 0) == player) {
        return true;
    }

    if (levels[0].getCell(2, 1) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(0, 1) == player) {
        return true;
    }

    if (levels[0].getCell(2, 2) == player &&
        levels[1].getCell(1, 2) == player &&
        levels[2].getCell(0, 2) == player) {
        return true;
    }

    if (levels[0].getCell(1, 2) == player &&
        levels[1].getCell(1, 1) == player &&
        levels[2].getCell(1, 0) == player) {
        return true;
    }

    // No winning line found
    return false;
}

/**
 * @brief Checks if the entire 3D board is full.
 * 
 * @return true if all levels are full, false otherwise.
 */
bool Board3D::isFull() const {
    return std::all_of(levels.begin(), levels.end(), 
        [](const Board& b) { return b.isFull(); });
}

/**
 * @brief Displays the 3D board using the provided output handler.
 * 
 * Outputs each level separately with a header.
 * 
 * @param output Shared pointer to an OutputHandler for displaying messages and boards.
 */
void Board3D::display(std::shared_ptr<OutputHandler> output) const {
    for (int level = 0; level < LEVELS; ++level) {
        output->displayMessage("--- Level " + std::to_string(level + 1) + " ---");
        output->displayBoard(levels[level]);
    }
}

