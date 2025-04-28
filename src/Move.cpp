/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Move.cpp
 * @brief Implementation of the Move class representing a player's move.
 */

#include "Move.h"

/**
 * @brief Constructs a Move with the given position and player marker.
 * 
 * @param pos The position on the board.
 * @param pl The player’s marker (Cell::X or Cell::O).
 */
Move::Move(Position pos, Cell pl) : position(pos), player(pl) {}

/**
 * @brief Equality operator to compare two Move objects.
 * 
 * Two moves are equal if both their positions and player markers are equal.
 * 
 * @param other The other Move to compare with.
 * @return true if moves are equal, false otherwise.
 */
bool Move::operator==(const Move& other) const {
    return position == other.position && player == other.player;
}

