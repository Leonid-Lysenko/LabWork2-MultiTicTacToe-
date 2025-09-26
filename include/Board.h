/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Board.h
 * @brief Represents the game board for Tic-Tac-Toe.
 */

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>
#include <optional>

class Move;

/**
 * @class Board
 * @brief Represents the Tic-Tac-Toe game board.
 * 
 * Provides methods to manipulate and query the board state.
 */
class Board {
public:
    static const int SIZE = 3; ///< Board size (3x3).

    /**
     * @brief Constructs a new empty board.
     */
    Board();

    /**
     * @brief Resets the board to an empty state.
     */
    void reset();

    /**
     * @brief Checks if the board is completely filled.
     * @return true if no empty cells remain, false otherwise.
     */
    bool isFull() const;

    /**
     * @brief Checks if the board is completely empty.
     * @return true if all cells are empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Checks if the given position is valid on the board.
     * @param row Row index (0-based).
     * @param col Column index (0-based).
     * @return true if the position is within board bounds.
     */
    bool isValidPosition(int row, int col) const;

    /**
     * @brief Returns the cell value at the specified position.
     * @param row Row index (0-based).
     * @param col Column index (0-based).
     * @return The cell value at the position, or Cell::EMPTY if invalid.
     */
    Cell getCell(int row, int col) const;

    /**
     * @brief Sets the cell value at the specified position.
     * @param row Row index (0-based).
     * @param col Column index (0-based).
     * @param value The cell value to set.
     */
    void setCell(int row, int col, Cell value);

    /**
     * @brief Returns the entire grid as a 2D vector.
     * @return A 2D vector representing the board cells.
     */
    std::vector<std::vector<Cell>> getGrid() const;

    /**
     * @brief Checks if a given move is valid.
     * @param move The move to validate.
     * @return true if the move is within bounds and the target cell is empty.
     */
    bool isMoveValid(const Move& move) const;

private:
    std::vector<std::vector<Cell>> grid; ///< 2D grid representing the board cells.
};

#endif // BOARD_H

