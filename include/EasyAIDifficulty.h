/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file EasyAIDifficulty.h
 * @brief Header file for the EasyAIDifficulty class.
 */

#ifndef EASY_AI_DIFFICULTY_H
#define EASY_AI_DIFFICULTY_H

#include "AIDifficulty.h"
#include "RandomGenerator.h"
#include <memory>

/**
 * @class EasyAIDifficulty
 * @brief Easy AI difficulty level that makes random moves.
 */
class EasyAIDifficulty : public AIDifficulty {
public:
    /**
     * @brief Constructor.
     * @param random Shared pointer to a random number generator (optional).
     */
    explicit EasyAIDifficulty(std::shared_ptr<RandomGenerator> random = nullptr);

    /**
     * @brief Calculates a random valid move on the board.
     * @param board The current game board.
     * @param aiMarker The AI's marker.
     * @return A random available position on the board.
     * @throws std::runtime_error if no moves are available.
     */
    Position calculateBestMove(const Board& board, Cell aiMarker) override;

private:
    std::shared_ptr<RandomGenerator> randomGenerator; ///< Random number generator.
};

#endif // EASY_AI_DIFFICULTY_H

