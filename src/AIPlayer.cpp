/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file AIPlayer.cpp
 * @brief Implementation of the AIPlayer class.
 */

#include "AIPlayer.h"
#include "GameRules.h"
#include <cstdlib>
#include <stdexcept>

/**
 * @brief Constructs an AIPlayer with the given marker and difficulty strategy.
 * @param marker The cell marker (X or O) for this AI player.
 * @param difficulty Unique pointer to the AI difficulty strategy.
 */
AIPlayer::AIPlayer(Cell marker, std::unique_ptr<AIDifficulty> difficulty) 
    : Player(marker, nullptr), difficulty(std::move(difficulty)) {}

/**
 * @brief Gets the AI player's move in classic 2D mode.
 * 
 * Throws an exception if the AI player has requested to exit.
 * Delegates move calculation to the difficulty strategy.
 * 
 * @param board The current game board.
 * @return The Move chosen by the AI.
 * @throws std::runtime_error if exit is requested.
 */
Move AIPlayer::getMove(const Board& board) {
    if (shouldExit()) {
        throw std::runtime_error("AI player exit");
    }
    Position pos = difficulty->calculateBestMove(board, getMarker());
    return Move(pos, getMarker());
}

/**
 * @brief Gets the AI player's move in 3D mode.
 * 
 * The AI attempts the following in order:
 * 1. Find a winning move for itself.
 * 2. Block the opponent's winning move.
 * 3. Choose a random level and calculate the best move on that level.
 * 
 * @param board The current 3D game board.
 * @return The 3D position of the move chosen by the AI.
 */
Position3D AIPlayer::get3DMove(const Board3D& board) {
    // 1. Check for a winning move for AI
    Position3D winMove = findWinningMove(board, getMarker());
    if (winMove.level != -1) {
        return winMove;
    }
    
    // 2. Check for blocking opponent's winning move
    Cell opponent = (getMarker() == Cell::X) ? Cell::O : Cell::X;
    Position3D blockMove = findWinningMove(board, opponent);
    if (blockMove.level != -1) {
        return blockMove;
    }
    
    // 3. Otherwise, pick a random level and calculate best move there
    int level = rand() % Board3D::LEVELS;
    Position pos = difficulty->calculateBestMove(board.getLevel(level), getMarker());
    return Position3D(level, pos);
}

/**
 * @brief Finds a winning move for the specified player on the 3D board.
 * 
 * Iterates through all levels and cells, simulating moves to check if they result in a win.
 * Returns the first winning move found.
 * 
 * @param board The 3D game board.
 * @param player The player marker to check winning moves for.
 * @return The Position3D of the winning move, or Position3D(-1, Position(-1, -1)) if none found.
 */
Position3D AIPlayer::findWinningMove(const Board3D& board, Cell player) const {
    for (int level = 0; level < Board3D::LEVELS; ++level) {
        for (int row = 0; row < Board::SIZE; ++row) {
            for (int col = 0; col < Board::SIZE; ++col) {
                if (board.getLevel(level).getCell(row, col) == Cell::EMPTY) {
                    // Create a temporary board to simulate the move
                    Board3D tempBoard = board;
                    tempBoard.makeMove(level, Move(Position(row, col), player));
                    // Check if this move results in a win
                    if (tempBoard.checkWin(player)) {
                        return Position3D(level, Position(row, col));
                    }
                }
            }
        }
    }
    // No winning move found
    return Position3D(-1, Position(-1, -1));
}

