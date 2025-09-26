/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Cell.h
 * @brief Header file for Cell enumeration.
 */

#ifndef CELL_H
#define CELL_H

/**
 * @enum Cell
 * @brief Represents the possible states of a cell on the board.
 */
enum class Cell {
    EMPTY,  ///< The cell is empty.
    X,      ///< The cell contains an X marker.
    O       ///< The cell contains an O marker.
};

#endif // CELL_H

