/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Validator.h
 * @brief Header file for the Validator class.
 */

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "Position.h"
#include "Position3D.h"
#include <string>
#include <stdexcept>

/**
 * @class Validator
 * @brief Validates user input.
 */
class Validator {
public:
    /**
     * @brief Validates input for classic mode.
     * @param input Input string (format: "row column").
     * @return Position on the board.
     * @throws std::invalid_argument if input is invalid.
     */
    Position validateInput(const std::string& input) const;
    
    /**
     * @brief Validates input for 3D mode.
     * @param input Input string (format: "level row column").
     * @return 3D position on the board.
     * @throws std::invalid_argument if input is invalid.
     */
    Position3D validate3DInput(const std::string& input) const;
};

#endif // VALIDATOR_H

