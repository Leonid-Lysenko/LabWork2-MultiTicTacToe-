/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_rules.cpp
 * @brief Unit tests for the GameRules class.
 */

#include <gtest/gtest.h>
#include "GameRules.h"
#include "Board.h"

/**
 * @brief Test winning condition detection in rows, columns, and diagonals.
 */
TEST(GameRulesTest, CheckWin) {
    GameRules rules;
    Board board;
    
    // Test win by row
    board.setCell(0, 0, Cell::X);
    board.setCell(0, 1, Cell::X);
    board.setCell(0, 2, Cell::X);
    EXPECT_TRUE(rules.checkWin(board, Cell::X));
    
    // Test win by column
    board.reset();
    board.setCell(0, 1, Cell::O);
    board.setCell(1, 1, Cell::O);
    board.setCell(2, 1, Cell::O);
    EXPECT_TRUE(rules.checkWin(board, Cell::O));
    
    // Test win by diagonal
    board.reset();
    board.setCell(0, 0, Cell::X);
    board.setCell(1, 1, Cell::X);
    board.setCell(2, 2, Cell::X);
    EXPECT_TRUE(rules.checkWin(board, Cell::X));
}

/**
 * @brief Test draw condition detection when the board is full with no winner.
 */
TEST(GameRulesTest, CheckDraw) {
    GameRules rules;
    Board board;
    
    // Fill board with no winner
    board.setCell(0, 0, Cell::X); board.setCell(0, 1, Cell::O); board.setCell(0, 2, Cell::X);
    board.setCell(1, 0, Cell::X); board.setCell(1, 1, Cell::X); board.setCell(1, 2, Cell::O);
    board.setCell(2, 0, Cell::O); board.setCell(2, 1, Cell::X); board.setCell(2, 2, Cell::O);
    
    EXPECT_TRUE(rules.checkDraw(board));
    EXPECT_FALSE(rules.checkWin(board, Cell::X));
    EXPECT_FALSE(rules.checkWin(board, Cell::O));
}

