/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Player.h
 * @brief Header file for the Player base class.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h"
#include "Board.h"
#include "Board3D.h"
#include "Position3D.h"
#include "InputHandler.h"

/**
 * @class Player
 * @brief Abstract base class representing a player.
 */
class Player {
public:
    /**
     * @brief Constructs a Player.
     * @param marker The player's marker (X or O).
     * @param inputHandler Optional shared pointer to an input handler.
     */
    Player(Cell marker, std::shared_ptr<InputHandler> inputHandler = nullptr);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Player();

    /**
     * @brief Returns the player's marker.
     * @return The cell marker.
     */
    Cell getMarker() const;

    /**
     * @brief Checks if the player requested to exit the game.
     * @return true if exit was requested.
     */
    virtual bool shouldExit() const;

    /**
     * @brief Gets the player's move in classic mode.
     * @param board The current board state.
     * @return The player's move.
     */
    virtual Move getMove(const Board& board) = 0;

    /**
     * @brief Gets the player's move in 3D mode.
     * @param board The current 3D board state.
     * @return The 3D position of the move including level.
     */
    virtual Position3D get3DMove(const Board3D& board) = 0;

protected:
    Cell marker; ///< Player's marker.
    std::shared_ptr<InputHandler> inputHandler; ///< Input handler.
};

#endif // PLAYER_H

