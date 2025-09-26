/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_ai.cpp
 * @brief Unit tests for AI player behaviors across different difficulty levels.
 */

#include <gtest/gtest.h>
#include "AIPlayer.h"
#include "EasyAIDifficulty.h"
#include "MediumAIDifficulty.h"
#include "HardAIDifficulty.h"
#include "Board.h"

/**
 * @brief Test that Easy AI selects a valid empty cell on the board.
 */
TEST(AITest, EasyAIMakesValidMove) {
    Board board;
    AIPlayer ai(Cell::O, std::make_unique<EasyAIDifficulty>());
    Move move = ai.getMove(board);
    EXPECT_TRUE(board.isValidPosition(move.position.row, move.position.col));
    EXPECT_TRUE(board.getCell(move.position.row, move.position.col) == Cell::EMPTY);
}

/**
 * @brief Test that Medium AI blocks the opponent's immediate winning move.
 */
TEST(AITest, MediumAIBlocksWin) {
    Board board;
    // Setup a situation where opponent is about to win
    board.setCell(0, 0, Cell::X);
    board.setCell(0, 1, Cell::X);
    
    AIPlayer ai(Cell::O, std::make_unique<MediumAIDifficulty>());
    Move move = ai.getMove(board);
    
    // AI should block by placing at (0, 2)
    EXPECT_EQ(move.position.row, 0);
    EXPECT_EQ(move.position.col, 2);
}

/**
 * @brief Test that Hard AI prefers winning moves when available.
 */
TEST(AITest, HardAIPrefersWinning) {
    Board board;
    // Setup a situation where AI can win
    board.setCell(0, 0, Cell::O);
    board.setCell(0, 1, Cell::O);
    
    AIPlayer ai(Cell::O, std::make_unique<HardAIDifficulty>());
    Move move = ai.getMove(board);
    
    // AI should win by placing at (0, 2)
    EXPECT_EQ(move.position.row, 0);
    EXPECT_EQ(move.position.col, 2);
}

