/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file MediumAIDifficulty.cpp
 * @brief Implementation of the MediumAIDifficulty class with basic strategic AI.
 */

#include "MediumAIDifficulty.h"
#include "EasyAIDifficulty.h"
#include <algorithm>

/**
 * @brief Calculates the best move for the AI using a medium difficulty strategy.
 * 
 * The strategy is:
 * 1. Win immediately if possible.
 * 2. Block opponent's winning move if imminent.
 * 3. Take center if available.
 * 4. Otherwise, make a random move.
 * 
 * @param board The current game board.
 * @param aiMarker The AI player's marker.
 * @return The chosen Position for the move.
 */
Position MediumAIDifficulty::calculateBestMove(const Board& board, Cell aiMarker) {
    // 1. Check if AI can win next move
    if (auto winMove = findWinningMove(board, aiMarker)) {
        return *winMove;
    }

    // 2. Check if opponent can win next move and block
    Cell humanMarker = (aiMarker == Cell::X) ? Cell::O : Cell::X;
    if (auto blockMove = findWinningMove(board, humanMarker)) {
        return *blockMove;
    }

    // 3. Take center if available
    if (board.getCell(1, 1) == Cell::EMPTY) {
        return Position(1, 1);
    }

    // 4. Otherwise, make a random move using EasyAI strategy
    EasyAIDifficulty easyAI;
    return easyAI.calculateBestMove(board, aiMarker);
}

/**
 * @brief Finds a winning move for the specified player, if any.
 * 
 * Iterates over all empty cells, simulates the move, and checks if it results in a win.
 * 
 * @param board The current game board.
 * @param marker The player's marker to check winning moves for.
 * @return An optional Position containing the winning move if found; std::nullopt otherwise.
 */
std::optional<Position> MediumAIDifficulty::findWinningMove(const Board& board, Cell marker) const {
    for (int row = 0; row < Board::SIZE; ++row) {
        for (int col = 0; col < Board::SIZE; ++col) {
            if (board.getCell(row, col) == Cell::EMPTY) {
                // Create a temporary board to test the move
                Board tempBoard = board;
                tempBoard.setCell(row, col, marker);
                
                if (rules.checkWin(tempBoard, marker)) {
                    return Position(row, col);
                }
            }
        }
    }
    return std::nullopt;
}

