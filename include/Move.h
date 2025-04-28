/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Move.h
 * @brief Header file for the Move class.
 */

#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Cell.h"

/**
 * @class Move
 * @brief Represents a move in the game.
 */
class Move {
public:
    Position position; ///< Position of the move.
    Cell player;       ///< Player making the move.

    /**
     * @brief Constructs a Move object.
     * @param pos Position of the move (default is (0,0)).
     * @param pl Player making the move (default is EMPTY).
     */
    Move(Position pos = Position(), Cell pl = Cell::EMPTY);
    
    /**
     * @brief Checks equality between two moves.
     * @param other Another move to compare with.
     * @return true if both moves are equal.
     */
    bool operator==(const Move& other) const;
};

#endif // MOVE_H

