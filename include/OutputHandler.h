/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file OutputHandler.h
 * @brief Header file for the OutputHandler interface.
 */

#ifndef OUTPUT_HANDLER_H
#define OUTPUT_HANDLER_H

#include <string>
#include "Board.h"
#include "GameState.h"

/**
 * @class OutputHandler
 * @brief Interface for output handling.
 */
class OutputHandler {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~OutputHandler() = default;

    /**
     * @brief Displays the game board.
     * @param board The board to display.
     */
    virtual void displayBoard(const Board& board) = 0;

    /**
     * @brief Displays the current game state.
     * @param state The game state to display.
     */
    virtual void displayGameState(GameState state) = 0;

    /**
     * @brief Displays a message.
     * @param message The message to display.
     */
    virtual void displayMessage(const std::string& message) = 0;
};

#endif // OUTPUT_HANDLER_H

