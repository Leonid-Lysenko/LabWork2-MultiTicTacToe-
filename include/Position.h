/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Position.h
 * @brief Header file for the Position class.
 */

#ifndef POSITION_H
#define POSITION_H

/**
 * @class Position
 * @brief Represents a position on the game board.
 */
class Position {
public:
    int row; ///< Row index (0..2).
    int col; ///< Column index (0..2).

    /**
     * @brief Constructs a Position.
     * @param r Row index (default 0).
     * @param c Column index (default 0).
     */
    Position(int r = 0, int c = 0);

    /**
     * @brief Checks equality between two positions.
     * @param other Another position to compare.
     * @return true if positions are equal.
     */
    bool operator==(const Position& other) const;

    /**
     * @brief Checks inequality between two positions.
     * @param other Another position to compare.
     * @return true if positions are not equal.
     */
    bool operator!=(const Position& other) const;
};

#endif // POSITION_H

