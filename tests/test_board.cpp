/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_board.cpp
 * @brief Unit tests for the Board class functionality.
 */

#include <gtest/gtest.h>
#include "Board.h"
#include "Move.h"
#include "Position.h"

/**
 * @brief Test that a newly initialized board is empty and not full.
 */
TEST(BoardTest, Initialization) {
    Board board;
    EXPECT_FALSE(board.isFull());
    EXPECT_TRUE(board.isEmpty());
    
    for (int i = 0; i < Board::SIZE; ++i) {
        for (int j = 0; j < Board::SIZE; ++j) {
            EXPECT_EQ(board.getCell(i, j), Cell::EMPTY);
        }
    }
}

/**
 * @brief Test setting and getting cell values on the board.
 */
TEST(BoardTest, SetAndGetCell) {
    Board board;
    board.setCell(1, 1, Cell::X);
    EXPECT_EQ(board.getCell(1, 1), Cell::X);
    EXPECT_NE(board.getCell(0, 0), Cell::X);
}

/**
 * @brief Test validation of moves on the board.
 */
TEST(BoardTest, MoveValidation) {
    Board board;
    Move valid(Position(1, 1), Cell::X);
    Move invalid(Position(3, 3), Cell::X);
    
    EXPECT_TRUE(board.isMoveValid(valid));
    EXPECT_FALSE(board.isMoveValid(invalid));
    
    board.setCell(1, 1, Cell::X);
    EXPECT_FALSE(board.isMoveValid(valid));
}

