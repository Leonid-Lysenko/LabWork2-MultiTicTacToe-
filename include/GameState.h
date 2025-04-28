/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file GameState.h
 * @brief Header file for the GameState enumeration.
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

/**
 * @enum GameState
 * @brief Represents the possible states of the game.
 */
enum class GameState {
    ONGOING,    ///< The game is ongoing.
    X_WON,      ///< Player X has won.
    O_WON,      ///< Player O has won.
    DRAW,       ///< The game ended in a draw.
    EXITED      ///< The game was exited by player request.
};

#endif // GAME_STATE_H

