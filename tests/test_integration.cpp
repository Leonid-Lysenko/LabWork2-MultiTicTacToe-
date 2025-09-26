/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_integration.cpp
 * @brief Reliable integration tests with controlled AI behavior.
 */

#include <gtest/gtest.h>
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "EasyAIDifficulty.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

/**
 * @class TestInput
 * @brief Mock input handler to simulate human moves for integration testing.
 */
class TestInput : public InputHandler {
public:
    /**
     * @brief Sets the sequence of human moves as strings.
     * @param inputs Vector of strings representing moves (e.g., "1 1").
     */
    void setMoves(const std::vector<std::string>& inputs) {
        this->inputs = inputs;
        current = 0;
    }

    /**
     * @brief Returns the next human move as a Position.
     * @return Position Parsed move position.
     * @throws std::invalid_argument if input format is invalid.
     */
    Position getInput() override {
        if (current >= inputs.size()) {
            return Position(-1, -1); // Special value indicating no more moves
        }
        return parseInput(inputs[current++]);
    }

    /**
     * @brief Disabled for classic mode; throws if called.
     * @throws std::runtime_error Always throws because 3D input is unsupported.
     */
    Position3D get3DInput() override {
        throw std::runtime_error("3D not supported");
    }

    /**
     * @brief Indicates whether the player has requested to exit.
     * @return true if all moves have been used, false otherwise.
     */
    bool shouldExit() const override {
        return current >= inputs.size();
    }

private:
    /**
     * @brief Parses a move string into a Position object.
     * @param input String representing the move (e.g., "1 1").
     * @return Position Parsed position.
     * @throws std::invalid_argument if input format is invalid.
     */
    Position parseInput(const std::string& input) {
        std::istringstream iss(input);
        int row, col;
        if (!(iss >> row >> col)) {
            throw std::invalid_argument("Invalid input");
        }
        return Position(row-1, col-1);
    }

    std::vector<std::string> inputs; ///< Sequence of moves.
    size_t current = 0;              ///< Current move index.
};

/**
 * @class TestOutput
 * @brief Custom output handler to capture the last board state.
 */
class TestOutput : public ConsoleOutput {
public:
    /**
     * @brief Captures the current board state.
     * @param board Current board.
     */
    void displayBoard(const Board& board) override {
        lastBoard = board;
    }

    /**
     * @brief Returns the last captured board state.
     * @return Board Last board.
     */
    Board getLastBoard() const { return lastBoard; }

private:
    Board lastBoard; ///< Last displayed board.
};

/**
 * @class ControlledAIPlayer
 * @brief AI player with deterministic move selection for testing.
 *
 * Selects the first available empty cell on the board.
 */
class ControlledAIPlayer : public AIPlayer {
public:
    using AIPlayer::AIPlayer;

    /**
     * @brief Returns the first available empty cell as the move.
     * @param board Current board state.
     * @return Move Selected move.
     * @throws std::runtime_error if no empty cells are available.
     */
    Move getMove(const Board& board) override {
        for (int row = 0; row < Board::SIZE; ++row) {
            for (int col = 0; col < Board::SIZE; ++col) {
                if (board.getCell(row, col) == Cell::EMPTY) {
                    return Move(Position(row, col), getMarker());
                }
            }
        }
        throw std::runtime_error("No empty cells");
    }
};

/**
 * @class IntegrationTest
 * @brief Integration test fixture for testing game flow with controlled AI.
 */
class IntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        input = std::make_shared<TestInput>();
        output = std::make_shared<TestOutput>();
    }

    /**
     * @brief Simulates a game with specified human moves against controlled AI.
     * @param humanMoves Vector of human move strings.
     * @return GameState Final game state after simulation.
     */
    GameState simulateTurns(const std::vector<std::string>& humanMoves) {
        input->setMoves(humanMoves);
        
        auto human = std::make_unique<HumanPlayer>(Cell::X, input);
        auto ai = std::make_unique<ControlledAIPlayer>(Cell::O, 
                  std::make_unique<EasyAIDifficulty>());
        
        Game game(std::move(human), std::move(ai), output);
        game.start();
        return game.getState();
    }

    /**
     * @brief Returns the Cell value at specified board coordinates.
     * @param row Row index.
     * @param col Column index.
     * @return Cell Cell value at position.
     */
    Cell getCell(int row, int col) const {
        return output->getLastBoard().getCell(row, col);
    }

    std::shared_ptr<TestInput> input;
    std::shared_ptr<TestOutput> output;
};

/**
 * @brief Test that AI takes the first available cell after human moves.
 */
TEST_F(IntegrationTest, AITakesFirstAvailableCell) {
    simulateTurns({"2 2"}); // Human moves center
    
    // AI should move to (0, 0) - first available cell
    EXPECT_EQ(getCell(0, 0), Cell::O);
}

/**
 * @brief Test AI response to human corner move.
 */
TEST_F(IntegrationTest, AIRespondsToCornerMove) {
    simulateTurns({"1 1"}); // Human moves corner
    
    // AI should move to (0, 1) - next available cell
    EXPECT_EQ(getCell(0, 1), Cell::O);
}

/**
 * @brief Test AI blocks human's winning move.
 */
TEST_F(IntegrationTest, AIBlocksWin) {
    simulateTurns({"1 1", "1 3", "3 3"});
    
    // AI should block by moving to center (1, 1)
    EXPECT_EQ(getCell(1, 1), Cell::O);
}

/**
 * @brief Test human player wins vertically.
 */
TEST_F(IntegrationTest, HumanWinsVertically) {
    simulateTurns({
        "1 1", // X
        "1 2", // X
        "2 1", // X
        "2 2", // O
        "3 1"  // X wins vertically
    });
    
    EXPECT_EQ(getCell(0, 0), Cell::X);
    EXPECT_EQ(getCell(1, 0), Cell::X);
    EXPECT_EQ(getCell(2, 0), Cell::X);
}

