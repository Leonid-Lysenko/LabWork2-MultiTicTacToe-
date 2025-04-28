/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file HumanPlayer.h
 * @brief Header file for the HumanPlayer class.
 */

#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Validator.h"

/**
 * @class HumanPlayer
 * @brief Class representing a human player.
 */
class HumanPlayer : public Player {
public:
    /**
     * @brief Constructs a HumanPlayer.
     * @param marker The player's marker.
     * @param inputHandler Shared pointer to an input handler.
     */
    HumanPlayer(Cell marker, std::shared_ptr<InputHandler> inputHandler);

    /**
     * @brief Gets the player's move in classic mode.
     * @param board The current board state.
     * @return The player's move.
     */
    Move getMove(const Board& board) override;

    /**
     * @brief Gets the player's move in 3D mode.
     * @param board The current 3D board state.
     * @return The 3D position of the move including level.
     */
    Position3D get3DMove(const Board3D& board) override;

private:
    Validator validator; ///< Input validator.
};

#endif // HUMAN_PLAYER_H

