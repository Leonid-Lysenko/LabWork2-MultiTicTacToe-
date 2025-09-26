/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file ConsoleInput.cpp
 * @brief Implementation of the ConsoleInput class for handling user input via console.
 */

#include "ConsoleInput.h"
#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Constructs a ConsoleInput object with a Validator.
 * @param validator Validator instance used to validate user input.
 */
ConsoleInput::ConsoleInput(Validator validator) 
    : validator(std::move(validator)), exitRequested(false) {}

/**
 * @brief Prompts the user to enter a move in classic 2D mode.
 * 
 * Continuously reads input from the console until a valid move is entered or exit is requested.
 * Recognizes "exit" or "quit" commands to signal game exit.
 * 
 * @return Validated Position entered by the user.
 * @throws std::runtime_error if the user requests to exit.
 */
Position ConsoleInput::getInput() {
    while (true) {
        std::string input;
        std::cout << "Enter your move (row and column, e.g. '1 2') or 'exit' to quit: ";
        std::getline(std::cin, input);
        
        // Check for exit commands
        if (input == "exit" || input == "quit") {
            exitRequested = true;
            throw std::runtime_error("Player requested exit");
        }
        
        try {
            // Validate and return position
            return validator.validateInput(input);
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
        }
    }
}

/**
 * @brief Prompts the user to enter a move in 3D mode.
 * 
 * Continuously reads input from the console until a valid 3D move is entered or exit is requested.
 * Recognizes "exit" or "quit" commands to signal game exit.
 * 
 * @return Validated Position3D entered by the user.
 * @throws std::runtime_error if the user requests to exit.
 */
Position3D ConsoleInput::get3DInput() {
    while (true) {
        std::string input;
        std::cout << "Enter level, row and column (e.g. '1 2 2') or 'exit' to quit: ";
        std::getline(std::cin, input);
        
        // Check for exit commands
        if (input == "exit" || input == "quit") {
            exitRequested = true;
            throw std::runtime_error("Player requested exit");
        }
        
        try {
            // Validate and return 3D position
            return validator.validate3DInput(input);
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
        }
    }
}

/**
 * @brief Returns whether the user has requested to exit.
 * 
 * @return true if exit was requested, false otherwise.
 */
bool ConsoleInput::shouldExit() const {
    return exitRequested;
}

