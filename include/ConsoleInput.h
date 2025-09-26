/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file ConsoleInput.h
 * @brief Header file for the ConsoleInput class.
 */

#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H

#include "InputHandler.h"
#include "Validator.h"

/**
 * @class ConsoleInput
 * @brief Handles input from the console.
 * 
 * Supports reading moves in both classic and 3D modes,
 * with input validation and exit request detection.
 */
class ConsoleInput : public InputHandler {
public:
    /**
     * @brief Constructs a ConsoleInput with an optional validator.
     * @param validator Input validator (default constructs a new Validator).
     */
    explicit ConsoleInput(Validator validator = Validator());

    /**
     * @brief Gets a move input from the console (classic mode).
     * @return Position on the board.
     * @throws std::runtime_error if the user requests exit.
     */
    Position getInput() override;
    
    /**
     * @brief Gets a 3D move input from the console.
     * @return 3D position including level.
     * @throws std::runtime_error if the user requests exit.
     */
    Position3D get3DInput() override;
    
    /**
     * @brief Checks if the user requested to exit the game.
     * @return true if exit was requested.
     */
    bool shouldExit() const override;

private:
    Validator validator; ///< Input validator.
    mutable bool exitRequested = false; ///< Flag indicating exit request.
};

#endif // CONSOLE_INPUT_H

