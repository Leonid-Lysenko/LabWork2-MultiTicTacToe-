/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Validator.cpp
 * @brief Implementation of the Validator class for validating user input.
 */

#include "Validator.h"
#include "Board.h"
#include "Board3D.h"
#include <sstream>
#include <stdexcept>

/**
 * @brief Validates user input for classic 2D mode.
 * 
 * Parses the input string expecting two integers separated by space (row and column).
 * Checks for extra characters and validates coordinate ranges.
 * 
 * @param input The input string to validate.
 * @return A Position object with zero-based indices.
 * @throws std::invalid_argument if input format is invalid or coordinates are out of range.
 */
Position Validator::validateInput(const std::string& input) const {
    std::istringstream iss(input);
    int row, col;
    
    if (!(iss >> row >> col)) {
        throw std::invalid_argument("Invalid input format. Expected two numbers separated by space (e.g. '1 2').");
    }
    
    // Check for extra characters after coordinates
    std::string remaining;
    if (iss >> remaining) {
        throw std::invalid_argument("Extra characters detected after coordinates.");
    }
    
    if (row < 1 || row > Board::SIZE || col < 1 || col > Board::SIZE) {
        throw std::invalid_argument("Coordinates must be between 1 and " + std::to_string(Board::SIZE) + ".");
    }
    
    // Convert to zero-based indices
    return Position(row - 1, col - 1);
}

/**
 * @brief Validates user input for 3D mode.
 * 
 * Parses the input string expecting three integers separated by spaces (level, row, column).
 * Validates the level and delegates row/column validation to validateInput().
 * 
 * @param input The input string to validate.
 * @return A Position3D object with zero-based indices.
 * @throws std::invalid_argument if input format is invalid or coordinates are out of range.
 */
Position3D Validator::validate3DInput(const std::string& input) const {
    std::istringstream iss(input);
    int level, row, col;
    
    if (!(iss >> level >> row >> col)) {
        throw std::invalid_argument("Invalid input format. Expected: level row column (e.g. '1 2 2').");
    }
    
    if (level < 1 || level > Board3D::LEVELS) {
        throw std::invalid_argument("Level must be between 1 and " + std::to_string(Board3D::LEVELS) + ".");
    }
    
    // Use existing validateInput to check row and column
    try {
        Position pos = validateInput(std::to_string(row) + " " + std::to_string(col));
        return Position3D(level - 1, pos);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument(std::string("Error in coordinates: ") + e.what());
    }
}

