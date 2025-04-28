/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file NoMoveAIDifficulty.h
 * @brief Stub AI that does not make any moves (for testing purposes).
 */

#ifndef NO_MOVE_AI_DIFFICULTY_H
#define NO_MOVE_AI_DIFFICULTY_H

#include "AIDifficulty.h"
#include "Board3D.h"
#include <stdexcept>

/**
 * @class NoMoveAIDifficulty
 * @brief AI stub that throws exceptions instead of making moves.
 * 
 * Used for testing scenarios where AI moves are not expected.
 */
class NoMoveAIDifficulty : public AIDifficulty {
public:
    /**
     * @brief Throws exception when asked to calculate a best move in 2D.
     * @param board The current game board.
     * @param aiMarker The AI's marker.
     * @throws std::runtime_error Always throws to indicate no moves should be made.
     */
    Position calculateBestMove(const Board& board, Cell aiMarker) override {
        throw std::runtime_error("AI should not make moves in this test");
    }
    
    /**
     * @brief Throws exception when asked to calculate a best move in 3D.
     * @param board The current 3D game board.
     * @param aiMarker The AI's marker.
     * @throws std::runtime_error Always throws to indicate no moves should be made.
     */
    Position3D calculate3DBestMove(const Board3D& board, Cell aiMarker) override {
        throw std::runtime_error("AI should not make moves in

