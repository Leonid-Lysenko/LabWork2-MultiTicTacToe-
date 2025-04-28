/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file ConsoleOutput.h
 * @brief Header file for the ConsoleOutput class.
 */

#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

#include <string>
#include "OutputHandler.h"

/**
 * @class ConsoleOutput
 * @brief Handles output of game information to the console.
 */
class ConsoleOutput : public OutputHandler {
public:
    /**
     * @brief Displays the current state of the board.
     * @param board The board to display.
     */
    void displayBoard(const Board& board) override;

    /**
     * @brief Displays the current game state message.
     * @param state The current game state.
     */
    void displayGameState(GameState state) override;

    /**
     * @brief Displays a general message to the console.
     * @param message The message string.
     */
    void displayMessage(const std::string& message) override;
};

#endif // CONSOLE_OUTPUT_H

