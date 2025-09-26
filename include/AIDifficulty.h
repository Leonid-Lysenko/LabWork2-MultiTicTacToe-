/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file AIDifficulty.h
 * @brief Header file for the AIDifficulty interface.
 */

#ifndef AI_DIFFICULTY_H
#define AI_DIFFICULTY_H

#include "Position.h"
#include "Board.h"
#include "Cell.h"

/**
 * @class AIDifficulty
 * @brief Interface for different AI difficulty levels.
 * 
 * This interface provides a method for calculating the best move
 * for the AI based on the current board state and the AI's marker.
 */
class AIDifficulty {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~AIDifficulty() = default;

    /**
     * @brief Calculates the best move for the AI.
     * @param board The current state of the board.
     * @param aiMarker The marker used by the AI.
     * @return The position for the next move.
     */
    virtual Position calculateBestMove(const Board& board, Cell aiMarker) = 0;
};

#endif // AI_DIFFICULTY_H

