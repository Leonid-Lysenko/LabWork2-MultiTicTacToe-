/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Board.cpp
 * @brief Implementation of the Board class representing the game board.
 */

#include "Board.h"
#include "Move.h"

/**
 * @brief Constructs a new Board and initializes it to empty.
 */
Board::Board() {
    reset();
}

/**
 * @brief Resets the board to an empty state.
 * 
 * Fills the internal grid with Cell::EMPTY values.
 */
void Board::reset() {
    grid = std::vector<std::vector<Cell>>(SIZE, std::vector<Cell>(SIZE, Cell::EMPTY));
}

/**
 * @brief Checks if the board is completely filled.
 * 
 * @return true if no empty cells remain, false otherwise.
 */
bool Board::isFull() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == Cell::EMPTY) {
                return false; // Found at least one empty cell
            }
        }
    }
    return true; // No empty cells found
}

/**
 * @brief Checks if the board is completely empty.
 * 
 * @return true if all cells are empty, false otherwise.
 */
bool Board::isEmpty() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell != Cell::EMPTY) {
                return false; // Found at least one non-empty cell
            }
        }
    }
    return true; // All cells are empty
}

/**
 * @brief Validates whether the given position is within board bounds.
 * 
 * @param row Row index to check.
 * @param col Column index to check.
 * @return true if position is valid, false otherwise.
 */
bool Board::isValidPosition(int row, int col) const {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

/**
 * @brief Retrieves the cell value at the specified position.
 * 
 * If the position is invalid, returns Cell::EMPTY.
 * 
 * @param row Row index.
 * @param col Column index.
 * @return The Cell value at the position or Cell::EMPTY if invalid.
 */
Cell Board::getCell(int row, int col) const {
    if (!isValidPosition(row, col)) {
        return Cell::EMPTY;
    }
    return grid[row][col];
}

/**
 * @brief Sets the cell value at the specified position.
 * 
 * Does nothing if the position is invalid.
 * 
 * @param row Row index.
 * @param col Column index.
 * @param value The Cell value to set.
 */
void Board::setCell(int row, int col, Cell value) {
    if (isValidPosition(row, col)) {
        grid[row][col] = value;
    }
}

/**
 * @brief Returns a copy of the internal grid representing the board.
 * 
 * @return 2D vector of Cell representing the board state.
 */
std::vector<std::vector<Cell>> Board::getGrid() const {
    return grid;
}

/**
 * @brief Checks if a given move is valid on the board.
 * 
 * A move is valid if the position is within bounds and the cell is empty.
 * 
 * @param move The Move to validate.
 * @return true if the move is valid, false otherwise.
 */
bool Board::isMoveValid(const Move& move) const {
    return isValidPosition(move.position.row, move.position.col) && 
           getCell(move.position.row, move.position.col) == Cell::EMPTY;
}

