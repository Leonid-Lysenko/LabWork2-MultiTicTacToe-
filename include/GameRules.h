/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file GameRules.h
 * @brief Header file for the GameRules class.
 */

#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "Board.h"
#include "Cell.h"

/**
 * @class GameRules
 * @brief Class containing the game rules logic.
 */
class GameRules {
public:
    /**
     * @brief Checks if the specified player has won.
     * @param board The game board.
     * @param marker The player's marker.
     * @return true if the player has a winning line.
     */
    bool checkWin(const Board& board, Cell marker) const;

    /**
     * @brief Checks if the game ended in a draw.
     * @param board The game board.
     * @return true if the game is a draw.
     */
    bool checkDraw(const Board& board) const;
};

#endif // GAME_RULES_H

