/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Board3D.h
 * @brief Header file for the Board3D class.
 */

#ifndef BOARD3D_H
#define BOARD3D_H

#include "OutputHandler.h"
#include "Board.h"
#include <array>
#include <memory>

/**
 * @class Board3D
 * @brief Represents a 3D Tic-Tac-Toe game board with multiple levels.
 * 
 * The board consists of 3 levels, each containing a classic 3x3 board.
 */
class Board3D {
public:
    static const int LEVELS = 3; ///< Number of levels in the 3D board.

    /**
     * @brief Constructs a new 3D board.
     */
    Board3D();

    /**
     * @brief Checks if a move is valid on a specific level.
     * @param level The level index (0-based).
     * @param move The move to validate.
     * @return true if the move is valid on the given level.
     */
    bool isMoveValid(int level, const Move& move) const;

    /**
     * @brief Executes a move on a specific level.
     * @param level The level index (0-based).
     * @param move The move to make.
     */
    void makeMove(int level, const Move& move);

    /**
     * @brief Checks if the specified player has won the game.
     * @param player The player's marker.
     * @return true if the player has a winning line.
     */
    bool checkWin(Cell player) const;

    /**
     * @brief Checks if all levels of the board are full.
     * @return true if every level is full.
     */
    bool isFull() const;

    /**
     * @brief Displays all levels of the 3D board using the output handler.
     * @param output Shared pointer to an OutputHandler instance.
     */
    void display(std::shared_ptr<OutputHandler> output) const;

    /**
     * @brief Returns a constant reference to the board at the specified level.
     * @param level The level index (0-based).
     * @return Reference to the Board at the given level.
     */
    const Board& getLevel(int level) const { 
        return levels.at(level); 
    }

private:
    std::array<Board, LEVELS> levels; ///< Array of 2D boards representing each level.

    /**
     * @brief Checks a line in 3D space for a winning condition.
     * @param startLevel Starting level index.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param dLevel Direction increment for level.
     * @param dRow Direction increment for row.
     * @param dCol Direction increment for column.
     * @param player The player's marker.
     * @return true if the line contains a winning combination for the player.
     */
    bool checkLine(int startLevel, int startRow, int startCol,
                   int dLevel, int dRow, int dCol, Cell player) const;
};

#endif // BOARD3D_H

