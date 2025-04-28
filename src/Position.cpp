/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Position.cpp
 * @brief Implementation of the Position class.
 */

#include "Position.h"

/**
 * @brief Constructs a Position.
 * @param r Row index (default 0).
 * @param c Column index (default 0).
 */
Position::Position(int r, int c) : row(r), col(c) {}

/**
 * @brief Checks equality between two positions.
 * @param other Another position to compare.
 * @return true if positions are equal.
 */
bool Position::operator==(const Position& other) const {
    return row == other.row && col == other.col;
}

/**
 * @brief Checks inequality between two positions.
 * @param other Another position to compare.
 * @return true if positions are not equal.
 */
bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}

