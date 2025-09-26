/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file AIPlayer.h
 * @brief Header file for the AIPlayer class.
 */

#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include "Player.h"
#include "AIDifficulty.h"
#include <memory>

/**
 * @class AIPlayer
 * @brief AI-controlled player.
 * 
 * Implements player behavior controlled by artificial intelligence,
 * supporting both classic and 3D game modes.
 */
class AIPlayer : public Player {
public:
    /**
     * @brief Constructs an AIPlayer.
     * @param marker The player's marker (X or O).
     * @param difficulty The AI difficulty level.
     */
    AIPlayer(Cell marker, std::unique_ptr<AIDifficulty> difficulty);

    /**
     * @brief Gets the next move from the AI (classic mode).
     * @param board The current board state.
     * @return The AI's move.
     */
    Move getMove(const Board& board) override;

    /**
     * @brief Gets the next move from the AI (3D mode).
     * @param board The current 3D board state.
     * @return The position of the move including the level.
     */
    Position3D get3DMove(const Board3D& board) override;
    
    /**
     * @brief Indicates whether the AI player should exit the game.
     * @return Always returns false for AI player.
     */
    bool shouldExit() const override { return false; }

private:
    std::unique_ptr<AIDifficulty> difficulty; ///< AI difficulty level.
    
    /**
     * @brief Finds a winning move in 3D space.
     * @param board The current 3D board state.
     * @param player The player's marker (X or O).
     * @return The position of the winning move, or (-1, -1, -1) if none found.
     */
    Position3D findWinningMove(const Board3D& board, Cell player) const;
};

#endif // AI_PLAYER_H

