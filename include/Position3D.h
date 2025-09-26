/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Position3D.h
 * @brief Header file for the Position3D structure.
 */

#ifndef POSITION3D_H
#define POSITION3D_H

#include "Position.h"

/**
 * @struct Position3D
 * @brief Represents a position in 3D space (level + position on the level).
 */
struct Position3D {
    int level;      ///< Level index (0-2).
    Position position; ///< Position on the level.
    
    /**
     * @brief Constructs a Position3D.
     * @param l Level index (default 0).
     * @param p Position on the level (default (0,0)).
     */
    Position3D(int l = 0, Position p = Position()) : level(l), position(p) {}
};

#endif // POSITION3D_H

