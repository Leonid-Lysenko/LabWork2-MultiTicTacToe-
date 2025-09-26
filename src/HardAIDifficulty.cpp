/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file HardAIDifficulty.cpp
 * @brief Implementation of the HardAIDifficulty class using the Minimax algorithm.
 */

#include "HardAIDifficulty.h"
#include <limits>
#include "Board.h"
#include "GameRules.h"

/**
 * @brief Calculates the best move for the AI using the Minimax algorithm.
 * 
 * Evaluates all possible moves and selects the one with the highest Minimax score.
 * 
 * @param board The current game board.
 * @param aiMarker The AI player's marker.
 * @return The best Position to move to.
 */
Position HardAIDifficulty::calculateBestMove(const Board& board, Cell aiMarker) {
    int bestScore = std::numeric_limits<int>::min();
    Position bestMove(-1, -1);
    Cell humanMarker = (aiMarker == Cell::X) ? Cell::O : Cell::X;

    // Iterate over all empty cells to evaluate moves
    for (int row = 0; row < Board::SIZE; ++row) {
        for (int col = 0; col < Board::SIZE; ++col) {
            if (board.getCell(row, col) == Cell::EMPTY) {
                Board tempBoard = board;
                tempBoard.setCell(row, col, aiMarker);
                int score = minimax(tempBoard, 0, false, aiMarker, humanMarker);
                
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = Position(row, col);
                }
            }
        }
    }

    return bestMove;
}

/**
 * @brief Recursive Minimax algorithm to evaluate board positions.
 * 
 * Maximizes AI's score and minimizes opponent's score to find optimal move.
 * 
 * @param board The current board state.
 * @param depth The current recursion depth.
 * @param isMaximizing True if maximizing AI's score, false if minimizing opponent's.
 * @param aiMarker The AI player's marker.
 * @param humanMarker The human player's marker.
 * @return The evaluated score of the board position.
 */
int HardAIDifficulty::minimax(Board& board, int depth, bool isMaximizing, Cell aiMarker, Cell humanMarker) const {
    // Check terminal states
    if (rules.checkWin(board, aiMarker)) return 10 - depth;  // AI wins
    if (rules.checkWin(board, humanMarker)) return depth - 10;  // Human wins
    if (board.isFull()) return 0;  // Draw

    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();
        // Try all possible moves for AI
        for (int row = 0; row < Board::SIZE; ++row) {
            for (int col = 0; col < Board::SIZE; ++col) {
                if (board.getCell(row, col) == Cell::EMPTY) {
                    board.setCell(row, col, aiMarker);
                    int score = minimax(board, depth + 1, false, aiMarker, humanMarker);
                    board.setCell(row, col, Cell::EMPTY);
                    bestScore = std::max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = std::numeric_limits<int>::max();
        // Try all possible moves for human opponent
        for (int row = 0; row < Board::SIZE; ++row) {
            for (int col = 0; col < Board::SIZE; ++col) {
                if (board.getCell(row, col) == Cell::EMPTY) {
                    board.setCell(row, col, humanMarker);
                    int score = minimax(board, depth + 1, true, aiMarker, humanMarker);
                    board.setCell(row, col, Cell::EMPTY);
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

