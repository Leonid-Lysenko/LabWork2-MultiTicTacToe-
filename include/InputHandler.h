/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file InputHandler.h
 * @brief Header file for the InputHandler interface.
 */

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Position.h"
#include "Position3D.h"

/**
 * @class InputHandler
 * @brief Interface for input handling.
 */
class InputHandler {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~InputHandler() = default;

    /**
     * @brief Gets input for classic mode.
     * @return Position on the board.
     */
    virtual Position getInput() = 0;
    
    /**
     * @brief Gets input for 3D mode.
     * @return 3D position including level.
     */
    virtual Position3D get3DInput() = 0;
    
    /**
     * @brief Checks if exit from the game was requested.
     * @return true if exit was requested.
     */
    virtual bool shouldExit() const = 0;
};

#endif // INPUT_HANDLER_H

