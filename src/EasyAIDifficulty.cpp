/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file EasyAIDifficulty.cpp
 * @brief Implementation of the EasyAIDifficulty class representing a simple AI.
 */

#include "EasyAIDifficulty.h"
#include <stdexcept>

/**
 * @brief Constructs an EasyAIDifficulty instance.
 * 
 * If no RandomGenerator is provided, creates a new one internally.
 * 
 * @param random Shared pointer to a RandomGenerator instance (optional).
 */
EasyAIDifficulty::EasyAIDifficulty(std::shared_ptr<RandomGenerator> random) 
    : randomGenerator(random ? random : std::make_shared<RandomGenerator>()) {}

/**
 * @brief Calculates the best move for the AI on the given board.
 * 
 * This easy AI selects a move randomly from all available empty cells.
 * 
 * @param board The current game board.
 * @param aiMarker The AI's marker (not used in this simple strategy).
 * @return The randomly selected position for the move.
 * @throws std::runtime_error if there are no available moves.
 */
Position EasyAIDifficulty::calculateBestMove(const Board& board, Cell aiMarker) {
    std::vector<Position> availableMoves;
    
    // Collect all empty positions on the board
    for (int row = 0; row < Board::SIZE; ++row) {
        for (int col = 0; col < Board::SIZE; ++col) {
            if (board.getCell(row, col) == Cell::EMPTY) {
                availableMoves.emplace_back(row, col);
            }
        }
    }

    if (availableMoves.empty()) {
        throw std::runtime_error("No available moves");
    }

    // Select a random index from available moves
    int randomIndex = randomGenerator->generate(0, static_cast<int>(availableMoves.size()) - 1);
    return availableMoves[randomIndex];
}

