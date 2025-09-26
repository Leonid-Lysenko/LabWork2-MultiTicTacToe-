/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file MediumAIDifficulty.h
 * @brief Header file for the MediumAIDifficulty class.
 */

#ifndef MEDIUM_AI_DIFFICULTY_H
#define MEDIUM_AI_DIFFICULTY_H

#include "AIDifficulty.h"
#include "GameRules.h"
#include <optional>

/**
 * @class MediumAIDifficulty
 * @brief Medium AI difficulty level.
 */
class MediumAIDifficulty : public AIDifficulty {
public:
    /**
     * @brief Calculates the best move for the AI.
     * @param board The current game board.
     * @param aiMarker The AI's marker.
     * @return The position of the best move.
     */
    Position calculateBestMove(const Board& board, Cell aiMarker) override;

protected:
    GameRules rules; ///< Game rules checker.

private:
    /**
     * @brief Finds a winning move for the given marker if available.
     * @param board The current game board.
     * @param marker The player's marker.
     * @return Optional position of the winning move, or std::nullopt if none found.
     */
    std::optional<Position> findWinningMove(const Board& board, Cell marker) const;
};

#endif // MEDIUM_AI_DIFFICULTY_H

