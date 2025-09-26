/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file HardAIDifficulty.h
 * @brief Header file for the HardAIDifficulty class.
 */

#ifndef HARD_AI_DIFFICULTY_H
#define HARD_AI_DIFFICULTY_H

#include "MediumAIDifficulty.h"

/**
 * @class HardAIDifficulty
 * @brief Hard AI difficulty level using the Minimax algorithm.
 */
class HardAIDifficulty : public MediumAIDifficulty {
public:
    /**
     * @brief Calculates the optimal move using the Minimax algorithm.
     * @param board The current game board.
     * @param aiMarker The AI's marker.
     * @return The best position to move.
     */
    Position calculateBestMove(const Board& board, Cell aiMarker) override;

private:
    /**
     * @brief Minimax algorithm implementation.
     * @param board The game board.
     * @param depth The current recursion depth.
     * @param isMaximizing True if the current player is maximizing.
     * @param aiMarker The AI's marker.
     * @param humanMarker The human player's marker.
     * @return The score evaluation of the board.
     */
    int minimax(Board& board, int depth, bool isMaximizing, Cell aiMarker, Cell humanMarker) const;
};

#endif // HARD_AI_DIFFICULTY_H

